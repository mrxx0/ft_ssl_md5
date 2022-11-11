<h1 align="center">Welcome to ft_ssl_md5 👋</h1>
<p>
  <img alt="Version" src="https://img.shields.io/badge/version-1.0-blue.svg?cacheSeconds=2592000" />
  </a>
</p>

<h1>What is ft_ssl_md5 ?</h1> 

<p>

* The goal of this project is to recode part of the OpenSSL program, specifically the MD5 Hashing Algorithm and few bonuses.

</p>


## Install

```sh
Compilation:

- make:	Compilation and creation of ft_ssl binary
- clean:	Delete only object files from library and ft_ssl
- fclean:	Delete all object files and binay from ft_ssl and libft
- re:		Recompile ft_ssl project

```

## Usage

```sh
usage: ft_ssl command [flags] [file/string]

Commands:
	md5
	sha256
	sha384
	sha512
Flags:
	-p -q -r -s
```
## Examples 

```sh

echo "hello there" | ./ft_ssl md5
(stdin)= 2d01d5d9c24034d54fe4fba0ede5182d

./ft_ssl sha256 -s "this is a test"
SHA256 ("this is a test") = 2e99758548972a8e8822ad47fa1017ff72f06f3ff6a016851f45c398732bc50c

echo "This is where the fun begins" | ./ft_ssl sha384 -p -q Makefile
This is where the fun begins
3ed397584b2c773a5e7f59ee62a8b89ce7ae5d8f9822fca2facc566356ca7ddb669dc14119fd8d097bb5f3f2b0e9f0be
4518c17a70eb4e0d3c02a615da0a17fc02e25c914c5916f19265b2ad94b7dba64a04464daed55646b85191a73285f86b

echo "Some things never change" | ./ft_ssl sha512 -p -s "In my books experience outrank everything" srcs/main.c
("Some things never change")= c65a3bf09761b21e1ca4868d5181937b2a081b5c86b6895f864fe04635d6f02c747ae0005732a94e26b4b1e1307346e3d0b9489e3ca60dc009e263bba5b7fbba
SHA512 ("In my books experience outrank everything") = b34da8515700f8a19a2a580e2c1581af13a63bf3d61f2c7747cebccb3a6c3277fedb33a74007dfcfe4ce4230a8d788e7fafa7902c80a691658b19a8297a76ac9
SHA512 (srcs/main.c) = 7be1dac35df833b2908950ae517d0ee4ae6f6192b11bfad09542fa190475e45d160f2a70828da42a19dc47b6941616ac4969e64ee1d744ed7f38f8b7394084e2
```

## Authors

👤 **mrxx0**

* GitHub: [@mrxx0](https://github.com/mrxx0)
***
