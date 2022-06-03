#include "includes/ft_ssl.h"
#include <stdlib.h>

void test_sha256(int user_choice)
{
	if (user_choice == 1)
	{
		printf("Testing string \"salut\" on sha256\n");
		system("./ft_ssl sha256 -s salut");
		system("echo -n \"salut\" | openssl sha256");
		printf("\nTesting string \"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab\" on sha256\n");
		system("./ft_ssl sha256 -s aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab");
		system("echo -n \"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab\" | openssl sha256");
		printf("\nTesting string \"hello there\" on sha256\n");
		system("./ft_ssl sha256 -s \"hello there\"");
		system("echo -n \"hello there\" | openssl sha256");
		printf("\n\nTesting with option for ft_ssl:\n");
		printf("-s :\n");
		system("./ft_ssl sha256 -s salut");
		printf("\n-s -q :\n");
		system("./ft_ssl sha256 -s -q salut");
		printf("\n-s -r :\n");
		system("./ft_ssl sha256 -s -r salut");
		printf("\n-s -r -q :\n");
		system("./ft_ssl sha256 -s -r -q salut");
	}
	else if (user_choice == 2)
	{
		printf("Testing file \"ft_ssl\" on sha256\n");
		system("./ft_ssl sha256 ft_ssl");
		system("openssl sha256 ft_ssl");
		printf("\nTesting file \"/bin/ls\" on sha256\n");
		system("./ft_ssl sha256 /bin/ls");
		system("openssl sha256 /bin/ls");
		printf("\nTesting file \"Makefile\" on sha256\n");
		system("./ft_ssl sha256 Makefile");
		system("openssl sha256 Makefile");
		printf("\n\nTesting with option for ft_ssl on \"ft_ssl\":\n");
		printf("nothing :\n");
		system("./ft_ssl sha256 ft_ssl");
		printf("\n-q :\n");
		system("./ft_ssl sha256 -q ft_ssl");
		printf("\n-r :\n");
		system("./ft_ssl sha256 -r ft_ssl");
		printf("\n-r -q :\n");
		system("./ft_ssl sha256 -r -q ft_ssl");
	}
	else if (user_choice == 3)
	{
		printf("Testing stdin on sha256\n");
		system("echo \"TEEEEEEEEEEST\" | ./ft_ssl sha256");
		system("echo \"TEEEEEEEEEEST\" | openssl sha256");
		printf("\nTesting stdin on sha256\n");
		system("echo \"0\" | ./ft_ssl sha256");
		system("echo \"0\" | openssl sha256");
		printf("\nTesting stdin on sha256\n");
		system("echo \"This is a really nice test isn't it ?\" | ./ft_ssl sha256");
		system("echo \"This is a really nice test isn't it ?\" | openssl sha256");
		printf("\nTesting stdin on sha256\n");
		system("echo \"\" | ./ft_ssl sha256");
		system("echo \"\" | openssl sha256");
		printf("\n\nTesting with option for ft_ssl on stdin:\n");
		printf("nothing :\n");
		system("echo \"\" | ./ft_ssl sha256");
		printf("\n-q :\n");
		system("echo \"\" | ./ft_ssl sha256 -q");
		printf("\n-r :\n");
		system("echo \"\" | ./ft_ssl sha256 -r");
		printf("\n-r -q :\n");
		system("echo \"\" | ./ft_ssl sha256 -r -q");
	}
	else if (user_choice == 4)
	{
		printf("Testing with subject examples\n");
		system("echo \"42 is nice\" | ./ft_ssl sha256");
		printf("(stdin)= 35f1d6de0302e2086a4e472266efb3a9\n\n");
		system("echo \"42 is nice\" | ./ft_ssl sha256 -p");
		printf("(\"42 is nice\")= 35f1d6de0302e2086a4e472266efb3a9\n\n");
		system("echo \"Pity the living.\" | ./ft_ssl sha256 -q -r");
		printf("e20c3b973f63482a778f3fd1869b7f25\n\n");
		system("echo \"And above all,\" > file");
		system("./ft_ssl sha256 file");
		printf("sha256 (file) = 53d53ea94217b259c11a5a2d104ec58a\n\n");
		system("./ft_ssl sha256 -r file");
		printf("53d53ea94217b259c11a5a2d104ec58a file\n\n");
		system("./ft_ssl sha256 -s \"pity those that aren't following baerista on spotify.\"");
		printf("sha256 (\"pity those that aren't following baerista on spotify.\") = a3c990a1964705d9bf0e602f44572f5f\n\n");
		system("echo \"be sure to handle edge cases carefully\" | ./ft_ssl sha256 -p file");
		printf("(\"be sure to handle edge cases carefully\")= 3553dc7dc5963b583c056d1b9fa3349c\n");
		printf("sha256 (file) = 53d53ea94217b259c11a5a2d104ec58a\n\n");
		system("echo \"some of this will not make sense at first\" | ./ft_ssl sha256 file");
		printf("sha256 (file) = 53d53ea94217b259c11a5a2d104ec58a\n\n");
		system("echo \"but eventually you will understand\" | ./ft_ssl sha256 -p -r file");
		printf("(\"but eventually you will understand\")= dcdd84e0f635694d2a943fa8d3905281\n");
		printf("53d53ea94217b259c11a5a2d104ec58a file\n\n");
		system("echo \"GL HF let's go\" | ./ft_ssl sha256 -p -s \"foo\" file");
		printf("(\"GL HF let's go\")= d1e3cc342b6da09480b27ec57ff243e2\n");
		printf("sha256 (\"foo\") = acbd18db4cc2f85cedef654fccc4a4d8\n");
		printf("sha256 (file) = 53d53ea94217b259c11a5a2d104ec58a\n\n");
		system(" echo \"one more thing\" | ./ft_ssl sha256 -r -p -s \"foo\" file -s \"bar\"");
		printf("(\"one more thing\")= a0bd1876c6f011dd50fae52827f445f5\n");
		printf("acbd18db4cc2f85cedef654fccc4a4d8 \"foo\"\n");
		printf("53d53ea94217b259c11a5a2d104ec58a file\n");
		printf("ft_ssl: sha256: -s: No such file or directory\n");
		printf("ft_ssl: sha256: bar: No such file or directory\n\n");
		system(" echo \"just to be extra clear\" | ./ft_ssl sha256 -r -q -p -s \"foo\" file");
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
		test_sha256(user_choice);
		getchar();
		system("clear");
	}
}
