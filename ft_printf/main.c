//
//  main.c
//  ft_printf
//
//  Created by Anna Ershova on 6/23/20.
//  Copyright © 2020 Anna Ershova. All rights reserved.
//

//!!!printf("%-0-01-2.2s", "aaaaa");
#include <stdio.h>
#include "ft_printf.h"

int main() {

    //- Simply check each conversion without any flags 'cspdiuxX%'
    printf("\n====Simply check without any flags=====\n");
    ft_printf("hello");
    printf("\nhello\n");

    printf("\n====Simply check with flags====\n");
    ft_printf("int d or i: %d", 2);
    printf("\nint d or i: %d\n", 2);
    ft_printf("char: %c", 'a');
    printf("\nchar: %c\n", 'a');
    ft_printf("string: %s", "Hello AAAAAAAAAAAAAAA");
    printf("\nstring: %s", "Hello AAAAAAAAAAAAAAA\n");
    ft_printf("unsigned minus: %u", -6);
    printf("\nunsigned minus: %u\n", -6);
    ft_printf("unsigned: %u", 2147483647);
    printf("\nunsigned: %u\n", 2147483647);
    ft_printf("Hex small: %x", 89778116);
    printf("\nHex small: %x\n", 89778116);
    ft_printf("Hex big: %X", 89778116);
    printf("\nHex big: %X\n", 89778116);

    char *test = "alalalolololo hello aaaa";
    ft_printf("pointer: %p", test);
    printf("\npointer: %p\n", test);


    printf("\n");
    int aa = printf("string: %s", "Hello AAAAAAAAAAAAAAA");
    printf("\n");
    int bb = ft_printf("string: %s", "Hello AAAAAAAAAAAAAAA");
    printf("\n");
    printf("\na: %d ", aa);
    printf("\nb: %d ", bb);
    printf("\n");
    printf("\n");
    int c = printf("Hex small: %x", -89778116);
    printf("\n");
    int d = ft_printf("Hex small: %x", -89778116);
    printf("\n");
    printf("\nc: %d ", c);
    printf("\nd: %d ", d);
    printf("\n");

    printf("\n====0 or smallest int or empty string or null pointer====\n");
    printf("\n");
    ft_printf("NULL pointer: %p", NULL);
    printf("\nNULL pointer: %p\n", NULL);
    ft_printf("");
    printf("");
    printf("\n");
    printf("\n===== 's' conversion =====\n");

    //- Check the 'minimum field width' with values bigger, equal and smaller than the string
    int bigger = ft_printf("%80s", "s field width bigger");
    printf("\n");
    int bigger2 = printf("%80s", "s field width bigger");
    printf("\n");
    printf("s = %d\ns = %d\n\n", bigger, bigger2);
    int eaqual = ft_printf("%19s", "s field width equal");
    printf("\n");
    int eaqual1 = printf("%19s", "s field width equal");
    printf("\n");
    printf("s = %d\ns = %d\n\n", eaqual, eaqual1);
    int smaller = ft_printf("%5s", "s field width smaller");
    printf("\n");
    int smaller1 = printf("%5s", "s field width smaller");
    printf("\n");
    printf("s = %d\ns = %d\n\n", smaller, smaller1);

    //- Check the 'minimum field width' with values bigger, equal and smaller than the string with 0
    printf("\n===== 's' conversion with "" =====\n");
    int bigger3 = ft_printf("empty: %80s|", "\0");
    printf("\n");
    int bigger4 = printf("empty: %80s|", "\0");
    printf("\n");
    printf("s = %d\ns = %d\n", bigger3, bigger4);
    int eaqual3 = ft_printf("%20s|", "\0");
    printf("\n");
    int eaqual4 = printf("%20s|", "\0");
    printf("\n");
    printf("s = %d\ns = %d\n", eaqual3, eaqual4);
    int smaller3 = ft_printf("%5s|", "\0");
    printf("\n");
    int smaller4 = printf("%5s|", "\0");
    printf("\n");
    printf("s = %d\ns = %d\n", smaller3, smaller4);


    //- Try with multiple arguments/conversions
    //- Try the various conversions in the middle of a sentence (with other characters before and/or after)
    printf("\n\n========= MULTIPLE ===============\n\n");
    ft_printf("hello: !%s ...... %c ...%p... %d zzzzz", "AHAHA", 'Q', test, 123);
    printf("\n");
    printf("hello: !%s ...... %c ...%p... %d zzzzz", "AHAHA", 'Q', test, 123);
    printf("\n");




    //- Check the '.' with multiple precisions

    //- Use the 's' conversion for all the following test

    //- Check '*' as minimum field width (try values like negative one, zero etc.)

    //- Check '*' as precision (try values like negative one, zero etc.)

    //- Check '*' as both with/without one other flag (try values like negative one, zero etc.)


    //printf("%c\n");
    //ft_printf("%c");

    int a;
    int b;
    int i = 5;
    ft_printf("%.*u|", -100, i);
    printf("\n");
    printf("%.*u|", -100, i);

    printf("\n\n\\____________Testing cspdiuxX%%____________/\n\n");
    a = printf("%9s: %c %c %c %s %s %s %p %p %d %d %d %d %i %i %i %u %u %u %x %x %x %X %X %X %%\n", "printf", '!', '\0', 'a', NULL, "", "Hello, World", &i, NULL, 0, -2147483647, 0, 2020, 2147483647, -777, 10, 0, -100, 456, -10, 0, 2147483647, -1000, 0, 21);
    b = ft_printf("%9s: %c %c %c %s %s %s %p %p %d %d %d %d %i %i %i %u %u %u %x %x %x %X %X %X %%\n", "printf", '!', '\0', 'a', NULL, "", "Hello, World", &i, NULL, 0, -2147483647, 0, 2020, 2147483647, -777, 10, 0, -100, 456, -10, 0, 2147483647, -1000, 0, 21);
    printf("printf = %d, ft_printf = %d\n", a, b);
    printf("\n\n\\____________Testing -0.*____________/\n\n");
    a = printf("%9s: %5c%.c%3c %10.3s%-10s%*s %p %p %-20p %05.4d%-4d%3.1d %-*i%*i%0*i %8u%-.u%.*u %010x%.5x%*x %*.*X%-X%10.5X %5% %-5% %*%\n", "printf", '?', 'a', '3', "Hello", "Bye", -5, "Nice", &i, &i, NULL, 0, 12, 33, -5, 9, -5, 9, 5, 1, 456, 345, 2, 1, 34, 54, 4, 1, -5, 3, 5, 54, 51, -10);
    b = ft_printf("%9s: %5c%.c%3c %10.3s%-10s%*s %p %p %-20p %05.4d%-4d%3.1d %-*i%*i%0*i %8u%-.u%.*u %010x%.5x%*x %*.*X%-X%10.5X %5% %-5% %*%\n", "printf", '?', 'a', '3', "Hello", "Bye", -5, "Nice", &i, &i, NULL, 0, 12, 33, -5, 9, -5, 9, 5, 1, 456, 345, 2, 1, 34, 54, 4, 1, -5, 3, 5, 54, 51, -10);
    printf("printf = %d, ft_printf = %d\n", a, b);
    printf("\n\n\\____________Testing s with *____________/\n\n");
    a = printf("%9s: %*s %*s %*s %.*s %.*s %.*s %*.*s %*.*s %*.*s\n", "printf", -10, "Hello", 10, "Hello", 0, "Hello", 2, "Hello", 10, "Hello", -10, "Hello", 10, 3, "Hello", 4, 5, "Hello", -10, 2, "Hello");
    b = ft_printf("%9s: %*s %*s %*s %.*s %.*s %.*s %*.*s %*.*s %*.*s\n", "ft_printf", -10, "Hello", 10, "Hello", 0, "Hello", 2, "Hello", 10, "Hello", -10, "Hello", 10, 3, "Hello", 4, 5, "Hello", -10, 2, "Hello");
    printf("printf = %d, ft_printf = %d\n", a, b);


//    ft_printf("%.*d", -1, 0);
//    printf("|\n");
//    printf("%.*d", -1, 0);
//    printf("|\n");
//
//    ft_printf("%.-1d", 0);
//    printf("|\n");
//    printf("%.-1d", 0);
//    printf("|\n");

    ft_printf("%.3s", "hello");
    printf("|\n");
    printf("%.3s", "hello");
    printf("|\n");
    ft_printf(">------------<%4d>------------<", 972670952);
    printf("|\n");
    printf(">------------<%4d>------------<", 972670952);
    printf("|\n");

    ft_printf("%47.c", '2');
    printf("|\n");
    printf("%47.c", '2');
    printf("|\n"); 

    ft_printf("%*p", -9, NULL);
    printf("|\n");
    printf("%*p", -9, NULL);
    printf("|\n"); 

    ft_printf("%-*.*% ", 0, 0);
    printf("|\n");
    printf("%-*.*% ", 0, 0);
    printf("|\n");

    ft_printf("%-*.*% ", 12, -4);
    printf("|\n");
    printf("%-*.*% ", 12, -4);
    printf("|\n");

    ft_printf("%%%%");
    printf("|\n");
    printf("%%%%");
    printf("|\n"); 

    ft_printf("%% %*s ", 12, "uuuu");
    printf("|\n");
    printf("%% %*s ", 12, "uuuu");
    printf("|\n");

    ft_printf("%% %*s ", -12, "uuuu");
    printf("|\n");
    printf("%% %*s ", -12, "uuuu");
    printf("|\n");


    ft_printf("!!: %-*% ", 12);
    printf("|\n");
    printf("!!: %-*% ", 12);
    printf("|\n");

    ft_printf("%-*c", 20, 'w');
    printf("|\n");
    printf("%-*c", 20, 'w');
    printf("|\n");

    ft_printf("%*c", 20, 'w');
    printf("|\n");
    printf("%*c", 20, 'w');
    printf("|\n");

    ft_printf("%-*d", -20, 22);
    printf("|\n");
    printf("%-*d", -20, 22);
    printf("|\n");


    ft_printf("%-*.*d", -20, 10, 8);
    printf("|\n");
    printf("%-*.*d", -20, 10, 8);
    printf("|\n");

    ft_printf("%-*.*d", 20, -10, -44);
    printf("|\n");
    printf("%-*.*d", 20, -10, -44);
    printf("|\n");

    ft_printf("%-*.*d", 20, 10, -44);
    printf("|\n");
    printf("%-*.*d", 20, 10, -44);
    printf("|\n");
    ft_printf("%*.*d", -20, -10, -44);
    printf("|\n");
    printf("%*.*d", -20, -10, -44);
    printf("|\n");

    ft_printf("%-*.*u", -20, 10, 7);
    printf("|\n");
    printf("%-*.*u", -20, 10, 7);
    printf("|\n");

    ft_printf("%-*.*x", -20, 10, 66);
    printf("|\n");
    printf("%-*.*x", -20, 10, 66);
    printf("|\n");

    ft_printf("%-*.*s", -20, -10, "55");
    printf("|\n");
    printf("%-*.*s", -20, -10, "55");
    printf("|\n");


    ft_printf("%.*d", 0, 0);
    printf("|\n");
    printf("%.*d", 0, 0);
    printf("|\n");
    // int size_pres!!!! - after . ???
    ft_printf("%.*s", -234, "hello");
    printf("|\n");
    printf("%.*s", -234, "hello");
    printf("|\n");

    ft_printf("%-*.*s", 2, -234, "helloooooo");
    printf("|\n");
    printf("%-*.*s", 2, -234, "helloooooo");
    printf("|\n");

    ft_printf("%-*.*s", 2, -234, "helloooooo");
    printf("|\n");
    printf("%-*.*s", 2, -234, "helloooooo");
    printf("|\n");



    int k = ft_printf("%-32s", NULL);
    printf("|\n");
    int kk = printf("%-32s", NULL);
    printf("|\n");
    printf("values for NULL: %d and %d", k, kk);
    printf("|\n");

    int g = ft_printf("hello, %s.", NULL);
    printf("|\n");
    int gg = printf("hello, %s.", NULL);
    printf("|\n");
    printf("values for NULL: %d and %d", g, gg);
    printf("|\n");

    ft_printf("%-*.*s", -7, -3, "yolo");
    printf("|\n");
    printf("%-*.*s", -7, -3, "yolo");
    printf("|\n");

    ft_printf("%%-*.3s LYDI == |%-*.3s|", 5, "LYDI");
    printf("|\n");
    printf("%%-*.3s LYDI == |%-*.3s|", 5, "LYDI");
    printf("|\n");


    ft_printf("%% *.5i 42 == |% *.5i|", 4, 42);
//    ft_printf("%d", -2147483648);
    printf("|\n");
    printf("%% *.5i 42 == |% *.5i|", 4, 42);
//    printf("%d", -2147483648);
    printf("|\n");


    ft_printf("%-*i", 7, -54);
    printf("|\n");
    printf("%-*i", 7, -54);
    printf("|\n");

    ft_printf("%000*i", -7, -54);
    printf("|\n");
    printf("%000*i", -7, -54);
    printf("|\n");

    ft_printf("%.0x", 0);
    printf("|\n");
    printf("%.0x", 0);
    printf("|\n");

    ft_printf("Hex big: %020.11x", 89778116);
    printf("|\n");
    printf("Hex big: %020.11x", 89778116);
    printf("|\n");

    printf("%5x", 13862);
    printf("|\n");
    ft_printf("%5x", 13862);
    printf("|\n");

    ft_printf("%-22.5u", 27);
    printf("|\n");
    printf("%-22.5u", 27);
    printf("|\n");
//    printf("unsigned: %012.7u", 214);
//    printf("|\n");

    ft_printf("%.3d", 13862);
    printf("|\n");
    printf("%.3d", 13862);
    printf("|\n");

    ft_printf("%-1d", -14);
    printf("|\n");
    printf("%-1d", -14);
    printf("|\n");

    ft_printf("%-5.d", 0);
    printf("|\n");
    printf("%-5.d", 0);
    printf("|\n");

    ft_printf("%-8.3d", -8473);
    printf("|\n");
    printf("%-8.3d", -8473);
    printf("|\n");

    ft_printf("%-12.7d", 0); //-0001|
    printf("|\n");
    printf("%-12.7d", 0);
    printf("|\n");


    ft_printf("%000005.2d", 1); //   -1| ->5 width
    printf("|\n");
    printf("%000005.2d", 1);
    printf("|\n");

    ft_printf("%05d", -1); //-0001|
    printf("|\n");
    printf("%05d", -1); //   -1| ->5 width
    printf("|\n");

    ft_printf("%5.d", 0);
    printf("|\n");
    printf("%5.d", 0);
    printf("|\n");

    ft_printf("%2.d", 1);
    printf("|\n");
    printf("%2.d", 1);
    printf("|\n");

    ft_printf("%5.2d", 0);
    printf("|\n");
    printf("%5.2d", 0);
    printf("|\n");

    ft_printf("%-5.2d", 0);
    printf("|\n");
    printf("%-5.2d", 0);
    printf("|\n");



    ft_printf("%08.5d", 34);
    printf("|\n");
    printf("%08.5d", 34);
    printf("|\n");

    ft_printf("%8.3d", -8473);
    printf("|\n");
    printf("%8.3d", -8473);
    printf("|\n");

    ft_printf("%10.5d", -216);
    printf("|\n");
    printf("%10.5d", -216);
    printf("|\n");

    ft_printf("%.7d", -5263);
    printf("|\n");
    printf("%.7d", -5263);
    printf("|\n");

    ft_printf("%.013d", 5263);
    printf("|\n");
    printf("%.013d", 5263);
    printf("|\n");


    ft_printf("%.5d", 2);
    printf("|\n");
    printf("%.5d", 2);
    printf("|\n");

    ft_printf("this %d number", -267);
    printf("|\n");
    printf("this %d number", -267);
    printf("|\n");

    ft_printf("%5%");
    printf("|\n");
    printf("%5%");
    printf("|\n");

    ft_printf("%-5%");
    printf("|\n");
    printf("%-5%");
    printf("|\n");

    ft_printf("hello, %s.", NULL);
    printf("|\n");
    printf("hello, %s.", NULL);
    printf("|\n");


    ft_printf("this %d number", -267);
    printf("|\n");
    printf("this %d number", -267);
    printf("|\n");

    ft_printf("Hex small: %020x", -89778116);
    printf("|\n");
    printf("Hex small: %020x", -89778116);
    printf("|\n");

    ft_printf("Hex big: %020X", 89778116);
    printf("|\n");
    printf("Hex big: %020X", 89778116);
    printf("|\n");

    ft_printf("unsigned: %012.*u, %*.*u", 7 , 2140, 13, 14, 2140);
    printf("|\n");
    printf("unsigned: %012.*u, %*.*u", 7 , 2140, 13, 14, 2140);
    printf("|\n");

    ft_printf("unsigned: %012.7u", -214);
    printf("|\n");
    printf("unsigned: %012.7u", -214);
    printf("|\n");

//    ft_printf("unsigned: %00-0012.07u", 214);
//    printf("|\n");
//    printf("unsigned: %00-0012.07u", 214);
//    printf("|\n");

    ft_printf("char: %12c", 'a');
    printf("|\n");
    printf("char: %12c", 'a');
    printf("|\n");

    ft_printf("char: %-12c", 'b');
    printf("|\n");
    printf("char: %-12c", 'b');
    printf("|\n");

//    ft_printf("char: %012c", 'b');
//    printf("|\n");
//    printf("char: %012c", 'b');
//    printf("|\n");

    ft_printf("char: %*c string: %*s", 12, 'b', 12, "strstr");
    printf("|\n");
    printf("char: %*c string: %*s", 12, 'b', 12, "strstr");
    printf("|\n");

    ft_printf("%*.2s.....%*d", -12, "UUUUUU", 11, 234);
    printf("\n");
    printf("%*.2s.....%*d", -12, "UUUUUU", 11, 234);
    printf("\n");

    ft_printf(".....%*d", 10, 111);
    printf("\n");
    printf(".....%*d", 10 , 111);
    printf("\n");


    ft_printf("%*.2s.....%d", -12, "UUUUUU", 123);
    printf("\n");
    printf("%*.2s.....%d", -12, "UUUUUU", 123);
    printf("\n");

    ft_printf("%-12.2s.....%d", "UUUUUU", 133);
    printf("\n");
    printf("%-12.2s.....%d", "UUUUUU", 133);
    printf("\n");

//    ft_printf("%0-15.0d", 13);
//    printf("|\n");
//    printf("%0-15.0d", 13);
//    printf("|\n");

    ft_printf("%s%d","sss" ,23);
    printf("|\n");
    printf("%s%d","sss" ,23);
    printf("|\n");


//    ft_printf("%0-15.6d", -13);
//    printf("|\n");
//    printf("%0-15.6d", -13);
//    printf("|\n");

//    ft_printf("%0-15.6d", 13);
//    printf("|\n");
//    printf("%0-15.6d", 13);
//    printf("|\n");


    ft_printf("%015.6d", -13);
    printf("|\n");
    printf("%015.6d", -13);
    printf("|\n");

    ft_printf("%015d", -13);
    printf("|\n");
    printf("%015d", -13);
    printf("|\n");

    ft_printf("%-15d", -13);
    printf("|\n");
    printf("%-15d", -13);
    printf("|\n");

    int precision = 8;
    int biggerPrecision = 16;
    const char *greetings = "Hello world";

    ft_printf("|%16p|", greetings);
    printf("\n");
    printf("|%16p|", greetings);
    printf("\n");


    ft_printf("|%.8s|", greetings);
    printf("\n");
    printf("|%.8s|", greetings);
    printf("\n");
    ft_printf("|%.*s|", precision , greetings);//!
    printf("\n");
    printf("|%.*s|", precision , greetings);//!
    printf("\n");
    ft_printf("|%16s|", greetings);
    printf("\n");
    printf("|%16s|", greetings);
    printf("\n");
    ft_printf("|%*s|", biggerPrecision , greetings);
    printf("\n");
    printf("|%*s|", biggerPrecision , greetings);
    printf("\n");


    ft_printf("%13.1s123|", "AAABBBccc");
    printf("\n");
    printf("%13.1s123|", "AAABBBccc");
    printf("\n");

//    ft_printf("%13.-s|", "AAABBBccc");
//    printf("\n");
//    printf("%13.-s|", "AAABBBccc");
//    printf("\n");

    ft_printf("%12.0s", "aaaaa");
    printf("|\n");
    printf("%12.0s", "aaaaa");
    printf("|\n");
//

    char *test_pointer = "asasa";
    ft_printf("%p", test_pointer);
    printf("|\n");
    printf("%p", test_pointer);
    printf("|\n");
    ft_printf("%22p", test_pointer);
    printf("|\n");
    printf("%22p", test_pointer);
    printf("|\n");

    ft_printf("%p|...%s", test_pointer, "hello pointer");
    printf("|\n");
    printf("%p|...%s", test_pointer, "hello pointer");
    printf("|\n");
    ft_printf("%-22p", test_pointer);
    printf("|\n");
    printf("%-22p", test_pointer);
    printf("|\n");

    ft_printf("kkkk%12.1s|%.1s", "UUUUU", "KKK");
    printf("\n");
    printf("kkkk%12.1s|%.1s", "UUUUU", "KKK");
    printf("\n");

    ft_printf("%*.2s.....%d", -12, "UUUUUU", 123);
    printf("\n");
    printf("%*.2s.....%d", -12, "UUUUUU", 123);
    printf("\n");
    ft_printf("%*.4s", 12,"UUUUUUU");
    printf("\n");
    printf("%*.4s", 12,"UUUUUUU");
    printf("\n");
    ft_printf("%*.*s...wer123...%d", 12, 4, "UUUUUUU", 123);
    printf("\n");
    printf("%*.*s...wer123...%d", 12, 4, "UUUUUUU", 123);
    printf("\n");

    //just NULL
//    ft_printf("just NULL: ");
//    printf("|");
//    ft_printf(NULL);
//    printf("|\n");

    //just 0
    //printf("just 0: |");
    //ft_printf(0); //no crash
    //printf("|");
    //printf(0); // crash
    //printf("\n");

    ft_printf("%-.0s","aa");
    printf("|\n");
    printf("%-.0s","aa");
    printf("|\n");


    ft_printf("%-*s", -1, "0");
    printf("|\n");
    printf("%-*s", -1, "0");
    printf("|\n");

    ft_printf("%-*d", -1, 0);
    printf("|\n");
    printf("%-*d", -1, 0);
    printf("|\n");

    ft_printf("%-*s", -1, "");
    printf("|\n");
    printf("%-*s", -1, "");
    printf("|\n");
	sleep(8);
    //printf("ебать ты смог");
    return 0;
} 

/**
int main()
{
    int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";

    static char	a01;
static unsigned char a02;
static short a03;
static unsigned short a04;
static int a05;
static unsigned int a06;
static long a07;
static unsigned long a08;
static long long a09;
static unsigned long long a10;
static char *a11;
static void *a12;

    int nb1;
    int nb2;
    nb1 = ft_printf("%-16p%-16p%-16p%-16p%-16p%-16p", (void *)4294967300, (void *)4294967295, (void *)4294967295, (void *)4294967295, (void *)4294967295, (void *)4294967295);
    printf("|\n");
    nb2 = printf("%-16p%-16p%-16p%-16p%-16p%-16p", (void *)4294967300, (void *)4294967295, (void *)4294967295, (void *)4294967295, (void *)4294967295, (void *)4294967295);
    printf("|\n");
    nb1 = ft_printf("%-16p%-16p%-16p%-16p%-16p%-16p", (void *)209590960, (void *)209590960, (void *)209590960, (void *)209590960, (void *)209590960, (void *)209590960);
    printf("|\n");
    nb2 = printf("%-16p%-16p%-16p%-16p%-16p%-16p", (void *)209590960, (void *)209590960, (void *)209590960, (void *)209590960, (void *)209590960, (void *)209590960);
    printf("|\n");
//8, 8, 8, 4294967284, fffffff4, FFFFFFF4, 123456789, 75bcd15, 75BCD15, 0, 0, 0, 4282621618, ff439eb2, FF439EB2, 97, 61, 61, 2147483647, 7fffffff, 7FFFFFFF, 2147483648, 80000000, 80000000|
    printf("| ft_printf = %d | printf = %d |\n", nb1, nb2);

    nb1 = ft_printf("%-16.3p%-16.3p%-16.3p%-16.3p%-16.3p%-16.3p%-16.3p%-16.3p%-16.3p%-16.3p%-16.3p%-16.3p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
    printf("|\n");
    nb2 = printf("%-16.3p%-16.3p%-16.3p%-16.3p%-16.3p%-16.3p%-16.3p%-16.3p%-16.3p%-16.3p%-16.3p%-16.3p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
    printf("|\n");
    printf("| ft_printf = %d | printf = %d |\n", nb1, nb2);

    ft_printf("|%-16p|\n", &a01);
    printf("|%-16p|\n", &a01);
    ft_printf("%x, %X", a, a);
    printf("|\n");
    printf("%x, %X", a, a);
    printf("|\n"); 
    return 0;
    // 0xc7e1ab0
    // 0x1011ae030
} */ 

// gcc main.c -L. -lftprintf -o test
