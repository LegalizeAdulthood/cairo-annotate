#include <annotater/annotater.h>

#include <OpenImageIO/imageio.h>
#include <cairomm/cairomm.h>

#include <cstdlib>
#include <filesystem>
#include <memory>
#include <string>

namespace annotater
{

namespace
{

class Annotater
{
public:
    Annotater(std::string_view file);

    void writeText(Corner corner, std::string_view annotation);

private:
    std::string m_file;
};

Annotater::Annotater(std::string_view file) : m_file(file)
{
}

void Annotater::writeText(Corner corner, std::string_view annotation)
{
    std::unique_ptr sourceImage{OIIO::ImageInput::open(m_file)};
    OIIO::ImageSpec sourceSpec{sourceImage->spec_dimensions(0)};
    std::vector<unsigned char> pixels;
    pixels.resize(sourceSpec.width * sourceSpec.height * sourceSpec.nchannels);
    sourceImage->read_image(0, 0, 0, -1, OIIO::TypeDesc::UCHAR, pixels.data());

    auto surface{Cairo::ImageSurface::create(Cairo::Surface::Format::ARGB32, sourceSpec.width, sourceSpec.height)};
    auto ctx{Cairo::Context::create(surface)};

    ctx->rectangle(0.0, 0.0, sourceSpec.width, sourceSpec.height);
    ctx->set_source_rgba(0.0, 1.0, 0.0, 1.0);
    ctx->fill();
    surface->flush();

    std::unique_ptr destImage{OIIO::ImageOutput::create("c:/tmp/tmp.png")};
    OIIO::ImageSpec destSpec{sourceSpec};
    destSpec.set_format(OIIO::TypeDesc::UCHAR);
    destSpec.nchannels = 4;
    destImage->open("c:/tmp/tmp.png", destSpec);
    destImage->write_image(OIIO::TypeDesc::UCHAR, surface->get_data());
}

} // namespace

void annotateImage(std::string_view file, Corner position, std::string_view annotation)
{
    Annotater anno{file};
    anno.writeText(position, annotation);
}

} // namespace annotater
