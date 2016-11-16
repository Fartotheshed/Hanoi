#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <getopt.h>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[])     {

static struct option long_opts[] = {
    {"start",           required_argument, 0, 's'},
    {"end",             required_argument, 0, 'e'},
    {"num-disks"        required_argument, 0, 'n'},
    {0, 0, 0, 0}
};

char c;
int opt_index = 0;
short n = 0, start = 0, end = 0;
while ((c = getopt_long(argc, argv, "s:e:n:", long_opts, &opt_index)) != -1) {
    switch (c) {
      case 's':
       start = atoi(optarg);
       break;
      case 'e':
       end = atoi(optarg);
       break;
      case 'n':
       n = atoi(optarg);
       break;
      case '?':

       return 1;
   }
  }       


   return 0;
}



void towers(int n, int start, int mid




