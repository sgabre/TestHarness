
#include <stdio.h>

#include "getopt.h"

#include "lstimeCmd.h"

//LSTime -lng 12

struct option opts[] = {
	{"first", no_argument, 0, 'f'},
	{"second", required_argument, 0, 's'},
	{"third", optional_argument, 0, 't'},
	{0, 0, 0, 0}
};

int lstimeCmd(int argc, char **argv)
{
	int opt;
	
	getopt_clear();
	
	while((opt = getopt(argc, argv, ":if:lrx")) != -1)  
		{  
			switch(opt)  
			{  
				case 'i': 
				case 'l':  
				case 'r':  
					printf("option: %c\n", opt);  
					break;  
				case 'f':  
					printf("filename: %s\n", optarg);  
					break;  
				case ':':  
					printf("option needs a value\n");  
					break;  
				case '?':  
					printf("unknown option: %c\n", optopt); 
					break;  
			}  
		}  
	
	// optind is for the extra arguments 
	// which are not parsed 
	for(; optind < argc; optind++)
	{      
		printf("extra arguments: %s\n", argv[optind]);  
	}     

	return 0;
}