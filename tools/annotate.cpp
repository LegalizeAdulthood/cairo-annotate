#include <annotater/annotater.h>

int main(int argc, char *argv[])
{
    annotateImage(argv[1], annotater::Corner::TopLeft, argv[2]);

    return 0;
}
