/******************************************************/
/*                                                    */
/* CS107 Problems and Solutions (2014-2015)           */
/*                                                    */
/* starting point for practical 1: integer conversion */
/*                                                    */
/******************************************************/

#include <stdio.h> /* library needed to do the output */
#include <stdlib.h> /* library needed for EXIT_FAILURE, EXIT_SUCCESS, strtod() */
#include <errno.h> /* library needed to check for errors in strtod() */
#include <string.h> /* library needed for strlen */
#include <math.h> /* library needed for floor() */

int		checkArgs(int argc, char **argv); /* checks if arguments are okay, returns 1 if they are not */
void 	useArgs(char **argv, long *integer, char *bitsIn, char *bitsOut);
/* puts the 3rd argument in the appropriate variable */

void	output(char **argv, long integer, char *bitsIn, char *bitsOut);
/* produces the output as needed by the conversion type */
void	outputBits(char *bits); /* produces nice output for integer bits */

/* These are the actual conversion functions. */
/* Instead of defining one for each possible conversion we always convert to and from a value. */

long OnesComplement2Value(char *bits) {
    /* returns the value of the bits read as one's complement */
    
	fprintf(stderr, "Conversion 'OnesComplement2Value' not yet implemented.\n");
	exit(EXIT_FAILURE);
	return 0; /* unreachable code */
}

long TwosComplement2Value(char *bits) {
    /* returns the value of the bits read as two's complement */
    
	fprintf(stderr, "Conversion 'TwosComplement2Value' not yet implemented.\n");
	exit(EXIT_FAILURE);
	return 0; /* unreachable code */
}

long SignValue2Value(char *bits) {
    /* returns the value of the bits read as signed magnitude */

	fprintf(stderr, "Conversion 'SignValue2Value' not yet implemented.\n");
	exit(EXIT_FAILURE);
	return 0; /* unreachable code */
}

void Value2OnesComplement(long value, char *bits) {
    /* stores the one's complement representation of value in bits */
    
	fprintf(stderr, "Conversion 'Value2OnesComplement' not yet implemented.\n");
	exit(EXIT_FAILURE);
}

void Value2TwosComplement(long value, char *bits) {
    /* stores the two's complement representation of value in bits */
    
	fprintf(stderr, "Conversion 'Value2TwosComplement' not yet implemented.\n");
	exit(EXIT_FAILURE);
}

void Value2SignValue(long value, char *bits) {
    /* stores the signed magnitude representation of value in bits */
    
	fprintf(stderr, "Conversion 'Value2SignValue' not yet implemented.\n");
	exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
    long	integer; /* stores the number for conversion if it is an integer in decimal representation */
    char	bitsIn[17]; /* stores the up to 16 bits of the input to be converted if there are any; 0-terminated */
    char	bitsOut[17]; /* stores the up to 16 bits of the output if there are any; 0-terminated */
    
    /* check arguments for problems and exit if a problem exists */
    if ( checkArgs(argc, argv) )
        return EXIT_FAILURE; /* exit since there is a problem with the arguments */
    
    /* put the input number in the appropriate variable */
    useArgs(argv, &integer, bitsIn, bitsOut);
    
    /* do the actual conversion */
 	switch ( argv[1][0] ) {
            case 'o':
                integer=OnesComplement2Value(bitsIn);
                break;
            case 't':
                integer=TwosComplement2Value(bitsIn);
                break;
            case 's':
                integer=SignValue2Value(bitsIn);
                break;
            case 'd':
                break; /* nothing to do since we already have an integer */
            default:
                fprintf(stdout, "Internal error. This should not happen. Exiting.\n");
                exit(EXIT_FAILURE);
    }
	switch ( argv[2][0] ) {
            case 'o':
                Value2OnesComplement(integer, bitsOut);
                break;
            case 't':
                Value2TwosComplement(integer, bitsOut);
                break;
            case 's':
                Value2SignValue(integer, bitsOut);
                break;
            case 'd':
                break; /* nothing to do since we already have an integer */
            default:
                fprintf(stdout, "Internal error. This should not happen. Exiting.\n");
                exit(EXIT_FAILURE);
    }
    
    /* produce the output */
    output(argv, integer, bitsIn, bitsOut);
    
    return EXIT_SUCCESS; /* exit after normal operation */
}

void output(char **argv, long integer, char *bitsIn, char *bitsOut) {
    /* This function produces the output by first printing the input and */
    /* second printing the result of the conversion. */
    
    /* print input */
    if ( argv[1][0]=='d' ) {
        fprintf(stdout, "Input (decimal format): %ld\n", integer);
    }
    else {
        switch ( argv[1][0] ) {
            case 'o':
                fprintf(stdout, "Input (one's complement):\n");
                break;
            case 's':
                fprintf(stdout, "Input (sign value format):\n");
                break;
            case 't':
                fprintf(stdout, "Input (two's complement):\n");
                break;
            default:
                fprintf(stdout, "Internal error. This should not happen. Exiting.\n");
                exit(EXIT_FAILURE);
        }
        outputBits(bitsIn);
    }
    
    /* print output */
    if ( argv[2][0]=='d' ) {
        fprintf(stdout, "Output (decimal format): %ld\n", integer);
    }
    else {
        switch ( argv[2][0] ) {
            case 'o':
                fprintf(stdout, "Output (one's complement):\n");
                break;
            case 's':
                fprintf(stdout, "Output (sign value format):\n");
                break;
            case 't':
                fprintf(stdout, "Output (two's complement):\n");
                break;
            default:
                fprintf(stdout, "Internal error. This should not happen. Exiting.\n");
                exit(EXIT_FAILURE);
        }
        outputBits(bitsOut);
    }
}

void outputBits(char *bits) {
    /* This function produces nice output for integer bits. */
    int	i;	/* index variable in for loop */
    
    for ( i=0; i<17; i++ ) {
        if ( bits[i]=='0' || bits[i]=='1' )
            fputc(bits[i], stdout);
        if ( (strlen(bits)-i-1)%4==0 )
            fputc(' ', stdout);
    }
    fprintf(stdout, "\n");
}

void useArgs(char **argv, long *integer, char *bitsIn, char *bitsOut) {
    /* This function puts the third argument (the number to be converted) */
    /* in the appropriate variable, depending on the input type */
    
    int i; 			/* index variable in for loop */
    
    if ( argv[1][0]=='d' ) {
    	*integer = (long)strtod(argv[3], NULL);
    }
    else { /* all other types require bit strings */
        for ( i=0; i<(int)strlen(argv[3]); i++ )
            bitsIn[i] = argv[3][i];
        for ( i=(int)strlen(argv[3]); i<17; i++ )
            bitsIn[i] = (char)0;
    }
    
    if ( argv[1][0]==argv[2][0] && argv[1][0]!='d' ) {
        /* no conversion needed and not decimal numbers; we copy the input bits to the output bits and are done */
        for ( i=0; i<17; i++ )
            bitsOut[i] = bitsIn[i];
    }
}

int checkArgs(int argc, char **argv) {
    /* This function checks if the arguments are okay, i.e., if */
    /* (1) there are exactly three arguments */
    /* (2) if the first is a single character out of d, o, s, t */
    /* (3) if the second is a single character out of d, o, s, t */
    /* (4) if the third is not too long */
    /* (5) if the third consists only of characters compatible with the first argument */
    
    int	i; /* index variable in for loop */
    double number; /* used to store the number given as 3rd argument */
    char *endPointer; /* needed for strtod */
    
    /* (1) check if the are exactly three arguments */
    if ( argc!=4 ) {
        fprintf(stderr, "%s: Expected 3 arguments, received %d. Exiting.\n", 
                argv[0], argc-1);
        fprintf(stderr,  "Usage: %s type_in type_out number\n", argv[0]);
        fprintf(stderr, "type_in, type_out: either f, o, t, s, or d\n");
        fprintf(stderr, "   o for integer in one's complement\n");
        fprintf(stderr, "   t for integer in two's complement\n");
        fprintf(stderr, "   s for integer in signed magnitude\n");
        fprintf(stderr, "   d for decimal\n");
        fprintf(stderr,"number: number in format given by type_in\n");
        return 1; /* this flags an error */
    }
    
    /* (2) check if the first argument is a single character out of d, f, o, s, t */
    if ( (argv[1][1]!=(char)0) || (argv[1][0]!='d' && argv[1][0]!='o' && argv[1][0]!='s' && argv[1][0]!='t') ) {
        fprintf(stderr,"%s: First argument needs to be either o, t, s, or d; is %s. Exiting.\n",
                argv[0], argv[1]);
        return 1; /* this flags an error */
    }
    
    /* (3) check if the second argument is a single character out of d, f, o, s, t */
    if ( (argv[2][1]!=(char)0) || (argv[2][0]!='d' && argv[2][0]!='o' && argv[2][0]!='s' && argv[2][0]!='t') ) {
        fprintf(stderr,"%s: Second argument needs to be either o, t, s, or d; is %s. Exiting.\n",
                argv[0], argv[2]);
        return 1; /* this flags an error */
    }
    
    /* (4) check if the third argument is not too long */
    if ( strlen(argv[3])>16 ) {
        fprintf(stderr,"%s: Third parameter is too long for a number; is %s. Exiting.\n",
                argv[0], argv[3]);
        return 1;
    }
    
    /* (5) check if the third argument is not too short */
    if ( strlen(argv[3])<2 && argv[1][0]!='d' ) {
        fprintf(stderr,"%s: Third parameter is too short for a number; is %s. Exiting.\n",
                argv[0], argv[3]);
        return 1;
    }

    /* (6) check if the third argument is consists only of characters compatible with the first argument */
    if ( argv[1][0]=='d' ) {
        errno=0; /* set error flag to 0 */
        number=strtod(argv[3], &endPointer);
        if ( errno || *endPointer!=(char)0) {
            fprintf(stderr,"%s: Error in number argument. Could only convert %s to %g. Exiting.\n",
                    argv[0], argv[3], number);
            return 1;
        }
        if ( round(number)!=number ) {
            fprintf(stderr,"%s: Error in number argument. Expected integer, received float (%g from %s). Exiting.\n",
                    argv[0], number, argv[3]);
            return 1;
        }
        if ( number>32767 ) {
        	fprintf(stderr, "%s: Error in number argument. Number of out range, received (%g from %s) and allow only " 
        		"values less then 32768.\n", argv[0], number, argv[3]);
        	return 1;
        }
        if ( (number<(long)-32768) || ( (number<(long)-32767) && (argv[2][0]!='t') ) ) {
        	fprintf(stderr, "%s: Error in number argument. Number of out range, received (%g from %s) and allow only " 
        		"values larger than -2^15+1.\n", argv[0], number, argv[3]);
        	return 1;
        }
    }
    else {
        for ( i=0; i<(int)strlen(argv[3]); i++ ) { /* loop through the characters of the third argument */
            if ( argv[3][i]!='0' && argv[3][i]!='1' ) {
                fprintf(stderr,"%s: Only bits allowed; found %c. Exiting.\n",
                        argv[0], argv[3][i]);
                return 1;
            }
        }
    }
    
    return 0;
}
