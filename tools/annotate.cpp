#include <annotater/annotater.h>

#include <iostream>
#include <stdexcept>

namespace
{

void annotate_main(int argc, char *argv[])
{
    if (argc != 3)
    {
        throw std::runtime_error("Insufficient arguments; expected <file> <annotation>");
    }

    annotateImage(argv[1], annotater::Corner::TopLeft, argv[2]);
}

} // namespace

int main(int argc, char *argv[])
{
    try
    {
        annotate_main(argc, argv);

        return 0;
    }
    catch (const std::exception &bang)
    {
        std::cerr << "Unexpected exception: " << bang.what() << '\n';
        return 1;
    }
    catch (...)
    {
        std::cerr << "Unknown exception\n";
        return 2;
    }
}
