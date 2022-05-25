#include "includes/ft_ssl.h"
#include <stdlib.h>

void test_md5(int user_choice)
{
	if (user_choice == 1)
	{
		printf("Testing string \"salut\" on md5\n");
		system("./ft_ssl md5 -s salut");
		system("echo -n \"salut\" | openssl md5");
		printf("\nTesting string \"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab\" on md5\n");
		system("./ft_ssl md5 -s aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab");
		system("echo -n \"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab\" | openssl md5");
		printf("\nTesting string \"hello there\" on md5\n");
		system("./ft_ssl md5 -s \"hello there\"");
		system("echo -n \"hello there\" | openssl md5");
		printf("\n\nTesting with option for ft_ssl:\n");
		printf("-s :\n");
		system("./ft_ssl md5 -s salut");
		printf("\n-s -q :\n");
		system("./ft_ssl md5 -s -q salut");
		printf("\n-s -r :\n");
		system("./ft_ssl md5 -s -r salut");
		printf("\n-s -r -q :\n");
		system("./ft_ssl md5 -s -r -q salut");
	}
	else if (user_choice == 2)
	{
		printf("Testing file \"ft_ssl\" on md5\n");
		system("./ft_ssl md5 ft_ssl");
		system("openssl md5 ft_ssl");
		printf("\nTesting file \"/bin/ls\" on md5\n");
		system("./ft_ssl md5 /bin/ls");
		system("openssl md5 /bin/ls");
		printf("\nTesting file \"Makefile\" on md5\n");
		system("./ft_ssl md5 Makefile");
		system("openssl md5 Makefile");
		printf("\n\nTesting with option for ft_ssl on \"ft_ssl\":\n");
		printf("nothing :\n");
		system("./ft_ssl md5 ft_ssl");
		printf("\n-q :\n");
		system("./ft_ssl md5 -q ft_ssl");
		printf("\n-r :\n");
		system("./ft_ssl md5 -r ft_ssl");
		printf("\n-r -q :\n");
		system("./ft_ssl md5 -r -q ft_ssl");
	}
	else if (user_choice == 3)
	{
		printf("Testing stdin on md5\n");
		system("echo \"TEEEEEEEEEEST\" | ./ft_ssl md5");
		system("echo \"TEEEEEEEEEEST\" | openssl md5");
		printf("\nTesting stdin on md5\n");
		system("echo \"0\" | ./ft_ssl md5");
		system("echo \"0\" | openssl md5");
		printf("\nTesting stdin on md5\n");
		system("echo \"This is a really nice test isn't it ?\" | ./ft_ssl md5");
		system("echo \"This is a really nice test isn't it ?\" | openssl md5");
		printf("\nTesting stdin on md5\n");
		system("echo \"\" | ./ft_ssl md5");
		system("echo \"\" | openssl md5");
		printf("\n\nTesting with option for ft_ssl on stdin:\n");
		printf("nothing :\n");
		system("echo \"\" | ./ft_ssl md5");
		printf("\n-q :\n");
		system("echo \"\" | ./ft_ssl md5 -q");
		printf("\n-r :\n");
		system("echo \"\" | ./ft_ssl md5 -r");
		printf("\n-r -q :\n");
		system("echo \"\" | ./ft_ssl md5 -r -q");
	}
	else if (user_choice == 4)
	{
		printf("Testing with subject examples\n");
		system("echo \"42 is nice\" | ./ft_ssl md5");
		printf("(stdin)= 35f1d6de0302e2086a4e472266efb3a9\n\n");
		system("echo \"42 is nice\" | ./ft_ssl md5 -p");
		printf("(\"42 is nice\")= 35f1d6de0302e2086a4e472266efb3a9\n\n");
		system("echo \"Pity the living.\" | ./ft_ssl md5 -q -r");
		printf("e20c3b973f63482a778f3fd1869b7f25\n\n");
		system("echo \"And above all,\" > file");
		system("./ft_ssl md5 file");
		printf("MD5 (file) = 53d53ea94217b259c11a5a2d104ec58a\n\n");
		system("./ft_ssl md5 -r file");
		printf("53d53ea94217b259c11a5a2d104ec58a file\n\n");
		system("./ft_ssl md5 -s \"pity those that aren't following baerista on spotify.\"");
		printf("MD5 (\"pity those that aren't following baerista on spotify.\") = a3c990a1964705d9bf0e602f44572f5f\n\n");
		system("echo \"be sure to handle edge cases carefully\" | ./ft_ssl md5 -p file");
		printf("(\"be sure to handle edge cases carefully\")= 3553dc7dc5963b583c056d1b9fa3349c\n");
		printf("MD5 (file) = 53d53ea94217b259c11a5a2d104ec58a\n\n");
		system("echo \"some of this will not make sense at first\" | ./ft_ssl md5 file");
		printf("MD5 (file) = 53d53ea94217b259c11a5a2d104ec58a\n\n");
		system("echo \"but eventually you will understand\" | ./ft_ssl md5 -p -r file");
		printf("(\"but eventually you will understand\")= dcdd84e0f635694d2a943fa8d3905281\n");
		printf("53d53ea94217b259c11a5a2d104ec58a file\n\n");
		system("echo \"GL HF let's go\" | ./ft_ssl md5 -p -s \"foo\" file");
		printf("(\"GL HF let's go\")= d1e3cc342b6da09480b27ec57ff243e2\n");
		printf("MD5 (\"foo\") = acbd18db4cc2f85cedef654fccc4a4d8\n");
		printf("MD5 (file) = 53d53ea94217b259c11a5a2d104ec58a\n\n");
		system(" echo \"one more thing\" | ./ft_ssl md5 -r -p -s \"foo\" file -s \"bar\"");
		printf("(\"one more thing\")= a0bd1876c6f011dd50fae52827f445f5\n");
		printf("acbd18db4cc2f85cedef654fccc4a4d8 \"foo\"\n");
		printf("53d53ea94217b259c11a5a2d104ec58a file\n");
		printf("ft_ssl: md5: -s: No such file or directory\n");
		printf("ft_ssl: md5: bar: No such file or directory\n\n");
		system(" echo \"just to be extra clear\" | ./ft_ssl md5 -r -q -p -s \"foo\" file");
		printf("just to be extra clear\n");
		printf("3ba35f1ea0d170cb3b9a752e3360286c\n");
		printf("acbd18db4cc2f85cedef654fccc4a4d8\n");
		printf("53d53ea94217b259c11a5a2d104ec58a\n");
	}
	else
	{
		printf("Exiting\n");
		system("rm file");
		exit(EXIT_FAILURE);
	}
	printf("\nPress any key to continue...");
	getchar();
}

int main()
{
	int user_choice = -1;

	while (true)
	{
		printf("Which type do you want to test ? :\n1 : string\n2 : file\n3 : stdin\n4 : subject test\n5 : exit\n");
		scanf("%d", &user_choice);
		test_md5(user_choice);
		getchar();
		system("clear");
	}
}
