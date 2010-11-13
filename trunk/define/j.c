#define HELLO "hello world!" "hello world!" "hello world!"
#define HELLO2 HELLO HELLO
#define HELLO4 HELLO2 HELLO2
#define HELLO8 HELLO4 HELLO4
#define HELLO16 HELLO8 HELLO8
#define HELLO32 HELLO16 HELLO16
#define HELLO64 HELLO32 HELLO32
#define HELLO128 HELLO64 HELLO64
#define HELLO256 HELLO128 HELLO128
#define HELLO512 HELLO256 HELLO256
#define HELLO1024 HELLO512 HELLO512
int main(int argc,char *argv[]){printf("%s\n",HELLO256);return 0;}
