# 🔐 Unsafe Functions in C

These functions are considered **unsafe** because they do **not perform bounds checking**, which can lead to **buffer overflows**, **undefined behavior**, and **security vulnerabilities**.

---

## 📌 String Manipulation Functions

| Function      | Main Issue                                | Recommended Alternative              |
|---------------|--------------------------------------------|--------------------------------------|
| `gets()`      | No size check, removed in C11             | `fgets()`                            |
| `strcpy()`    | No buffer size validation                 | `strncpy()`, `strlcpy()` (if available), `snprintf()` |
| `strcat()`    | No buffer size validation                 | `strncat()`, `strlcat()` (if available) |
| `sprintf()`   | No output size limit                      | `snprintf()`                         |
| `vsprintf()`  | No output size limit                      | `vsnprintf()`                        |

---

## 📌 Memory Handling Functions

| Function      | Main Issue                                | Recommended Alternative              |
|---------------|--------------------------------------------|--------------------------------------|
| `memcpy()`    | No automatic overlap/bound checking       | Use carefully, or use `memmove()` if overlapping |
| `strncpy()`   | May not null-terminate the string         | `strlcpy()` (BSD), or a custom secure wrapper |
| `bcopy()`     | Obsolete and non-portable                 | `memmove()`                          |

---

## 📌 Input/Output Functions

| Function      | Main Issue                                | Recommended Alternative              |
|---------------|--------------------------------------------|--------------------------------------|
| `scanf()`     | May overflow if format string isn't safe  | Use width specifiers (`%Ns`) or `fgets()` + `sscanf()` |
| `sscanf()`    | Same as above                             | Check return value + specify sizes   |

---

## 📌 Number Conversion Functions

| Function      | Main Issue                                | Recommended Alternative              |
|---------------|--------------------------------------------|--------------------------------------|
| `atoi()` / `atol()` | No error handling, no bounds checking   | `strtol()`                           |
| `atoll()`     | Same as above                             | `strtoll()`                          |
| `atof()`      | Same as above                             | `strtof()` / `strtod()`              |

---

## 📌 System / Miscellaneous Functions

| Function      | Main Issue                                | Recommended Alternative              |
|---------------|--------------------------------------------|--------------------------------------|
| `system()`    | Risk of command injection                 | Use `exec()` family or a specific API |
| `realpath()`  | May overflow if buffer is too small       | Check buffer size explicitly         |
| `tmpnam()`    | Race condition vulnerability              | `mkstemp()`                          |
| `mktemp()`    | Same as above                             | `mkstemp()`                          |

---

## ✅ Security Tips

- Always **check buffer sizes**.
- Avoid using functions that don’t return errors or do bounds checking.
- Use **safe wrappers** or custom secure functions when needed.
- Compile with extra security flags:
  - `-Wall -Wextra -Werror`
  - `-fstack-protector-strong`
  - `-D_FORTIFY_SOURCE=2`
- Use analysis tools:
  - `Valgrind`
  - `AddressSanitizer (ASan)`
  - `Coverity`
  - `Clang Static Analyzer`

---

## 🔎 Optional: Detect Unsafe Functions in Source Code

```bash
# Search for common unsafe functions in source code
grep -rnE '\b(gets|strcpy|strcat|sprintf|vsprintf|scanf|sscanf|tmpnam|mktemp|bcopy|memcpy|system|atoi|atol|atoll|atof)\b' ./src
```

# 🧵 C Library Functions That Are Not Thread-Safe

Some C standard library functions are **not safe to use in multi-threaded programs**. This is typically because they use **static internal state**, **global variables**, or **shared resources** that are not protected by locks.

---

## 📌 Functions That Use Static Buffers

These functions return pointers to internal static buffers, which can be **overwritten by concurrent threads**.

| Function             | Issue                                                   | Safer Alternative / ARM Recommendation         |
|----------------------|----------------------------------------------------------|------------------------------------------------|
| `asctime()`          | Returns static string                                   | `_asctime_r()` – takes a user buffer           |
| `ctime()`            | Returns static string                                   | `ctime_r()` (POSIX)                            |
| `localtime()`        | Returns static `struct tm`                              | `_localtime_r()` – writes to user `struct tm`  |
| `gmtime()`           | Returns static `struct tm`                              | `gmtime_r()` (POSIX)                           |
| `strtok()`           | Uses static context for tokenizing                      | `_strtok_r()` – user context pointer required  |
| `tmpnam()`           | Returns static string                                   | `mkstemp()`                                    |
| `tmpfile()`          | Uses shared internal resources                          | Platform-dependent safety                      |
| `readdir()`          | Returns pointer to static structure                     | Use synchronization or switch to `scandir()`   |

> 🔎 **Note:** Reentrant versions (e.g., `_asctime_r()`) typically take additional parameters like user-provided buffers.

---

## 📌 Functions That Modify Global State

These functions read or write global settings or static memory without locking.

| Function             | Issue                                                   | Safer Alternative / Recommendation             |
|----------------------|----------------------------------------------------------|------------------------------------------------|
| `setlocale()`        | Global, unprotected state                               | Call once before threads start or use `_setlocale_r()` |
| `localeconv()`       | Not thread-safe                                         | Use ARM's `_get_lconv()` with user buffer      |
| `rand()`, `srand()`  | Use global static state                                 | Use `_rand_r()` / `_srand_r()` with buffer     |
| `strerror()`         | Returns pointer to static buffer                        | Use `strerror_r()` (POSIX)                     |
| `getenv()` / `putenv()` / `setenv()` / `unsetenv()` | Accesses/modifies global env vars | Synchronize manually or avoid if possible      |

> ⚠️ **ARM Note:** `_setlocale_r()` is not fully thread-safe when changing locale settings. Use it for thread-local reads but not concurrent writes.

---

## 📌 Math Functions with Global State

| Function                      | Issue                                         | Safer Usage / Note                            |
|-------------------------------|-----------------------------------------------|------------------------------------------------|
| `gamma()`, `lgamma()`, `lgammaf()`, `lgammal()` | Use global variable `_signgam`           | Not thread-safe; avoid in threaded context     |

---

## 📌 Multibyte String Conversion Functions

| Function                      | Issue                                         | Safer Alternative                              |
|-------------------------------|-----------------------------------------------|------------------------------------------------|
| `mblen()`, `mbtowc()`         | Internal static state                         | Avoid – not thread-safe                        |
| `mbrlen()`, `mbsrtowcs()`<br>`mbrtowc()`, `wcrtomb()`, `wcsrtombs()` | Thread-safe **only** if `mbstate_t*` is non-NULL | Use exclusive `mbstate_t` for each thread      |

---

## 📌 Other Functions

| Function             | Issue                                                   | Recommendation                                |
|----------------------|----------------------------------------------------------|------------------------------------------------|
| `exit()`             | Cleans up shared resources disrupting other threads     | Avoid calling from threads                     |
| `fcvt()`, `gcvt()`   | Use static buffers                                      | Use `snprintf()` or safer conversions          |

---

## ✅ Best Practices

- Always prefer **`_r` or reentrant** versions of functions when available.
- Protect access to **shared/global state** using **mutexes**.
- Avoid functions that return **static buffers** in multi-threaded code.
- Consider initializing **locale and environment** before starting threads.

---

## 🔍 Detect Non-Thread-Safe Functions in Source Code

```bash
grep -rnE '\b(asctime|ctime|gmtime|localtime|strtok|tmpnam|tmpfile|readdir|setlocale|localeconv|rand|srand|strerror|getenv|putenv|setenv|unsetenv|gamma|lgamma|lgammaf|lgammal|mblen|mbtowc|fcvt|gcvt|exit)\b' ./src
