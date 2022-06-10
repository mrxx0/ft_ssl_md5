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
		printf("(stdin)= a5482539287a4069ebd3eb45a13a47b1968316c442a7e69bc6b9c100b101d65d\n\n");
		system("echo \"42 is nice\" | ./ft_ssl sha256 -p");
		printf("(\"42 is nice\")= a5482539287a4069ebd3eb45a13a47b1968316c442a7e69bc6b9c100b101d65d\n\n");
		system("echo \"Pity the living.\" | ./ft_ssl sha256 -q -r");
		printf("40133cfe543247c1cae0ffb0003c1179ce9fb0046bee19f9fca167380643ba45\n\n");
		system("echo \"And above all,\" > file");
		system("./ft_ssl sha256 file");
		printf("sha256 (file) = f9eb9a5a063eb386a18525c074e1065c316ec434f911e0d7d59ba2d9fd134705\n\n");
		system("./ft_ssl sha256 -r file");
		printf("f9eb9a5a063eb386a18525c074e1065c316ec434f911e0d7d59ba2d9fd134705 file\n\n");
		system("./ft_ssl sha256 -s \"pity those that aren't following baerista on spotify.\"");
		printf("sha256 (\"pity those that aren't following baerista on spotify.\") = 7838c25c9debff86c584245d67b429186d3850c89da31c0b49b8d0380a3e14bf\n\n");
		system("echo \"be sure to handle edge cases carefully\" | ./ft_ssl sha256 -p file");
		printf("(\"be sure to handle edge cases carefully\")= ef9241f878a1da676104a81239792a2817bc0390a427ca20bad1a59030fd20c2\n");
		printf("sha256 (file) = f9eb9a5a063eb386a18525c074e1065c316ec434f911e0d7d59ba2d9fd134705\n\n");
		system("echo \"some of this will not make sense at first\" | ./ft_ssl sha256 file");
		printf("sha256 (file) = f9eb9a5a063eb386a18525c074e1065c316ec434f911e0d7d59ba2d9fd134705\n\n");
		system("echo \"but eventually you will understand\" | ./ft_ssl sha256 -p -r file");
		printf("(\"but eventually you will understand\")= 43da940057fd3b7453ee91b3a056a41343e6f0bce315570ed27e06c993a539da\n");
		printf("f9eb9a5a063eb386a18525c074e1065c316ec434f911e0d7d59ba2d9fd134705 file\n\n");
		system("echo \"GL HF let's go\" | ./ft_ssl sha256 -p -s \"foo\" file");
		printf("(\"GL HF let's go\")= f33201f3d70c9dccccec022e2ff0df2006e016f153f600407917d14955fbec22\n");
		printf("sha256 (\"foo\") = 2c26b46b68ffc68ff99b453c1d30413413422d706483bfa0f98a5e886266e7ae\n");
		printf("sha256 (file) = f9eb9a5a063eb386a18525c074e1065c316ec434f911e0d7d59ba2d9fd134705\n\n");
		system(" echo \"one more thing\" | ./ft_ssl sha256 -r -p -s \"foo\" file -s \"bar\"");
		printf("(\"one more thing\")= 720bbf63077e0bea3b70c87954123daa6fcf32f973f4d646622bd016b140ec75\n");
		printf("2c26b46b68ffc68ff99b453c1d30413413422d706483bfa0f98a5e886266e7ae \"foo\"\n");
		printf("f9eb9a5a063eb386a18525c074e1065c316ec434f911e0d7d59ba2d9fd134705 file\n");
		printf("ft_ssl: sha256: -s: No such file or directory\n");
		printf("ft_ssl: sha256: bar: No such file or directory\n\n");
		system(" echo \"just to be extra clear\" | ./ft_ssl sha256 -r -q -p -s \"foo\" file");
		printf("just to be extra clear\n");
		printf("41c3da28172faf72bb777d6a428b6d801427d02513c56cd9e3672f44383f8eee\n");
		printf("2c26b46b68ffc68ff99b453c1d30413413422d706483bfa0f98a5e886266e7ae\n");
		printf("f9eb9a5a063eb386a18525c074e1065c316ec434f911e0d7d59ba2d9fd134705\n");
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
