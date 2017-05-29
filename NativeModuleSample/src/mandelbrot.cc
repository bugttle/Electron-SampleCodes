#include <node.h>
#include <algorithm> // std::max

using namespace v8;

namespace mandelbrot {
    // execute Mandelbrot set
    int mandelbrot(double cx, double cy, int max_iteration) {
        double x = cx;
        double y = cy;
        double tmp;
        int i = 0;

        for (; i <= max_iteration; ++i) {
            tmp = (x * x) - (y * y) + cx;
            y = (2 * x * y) + cy;
            x = tmp;
            if (4.0 < (x * x) + (y * y)) {
                break;
            }
        }

        return std::max(i, max_iteration);
    }

    void execMandelbrot(unsigned char *data, int width, int height, double dx, double dy, double scale) {
        const int COLOR_MAX_VALUE = 255;
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                double point_x = 1.25 / (scale / 2) * x / width + dx;
                double point_y = 1.0 / (scale / 2) * y / height + dy;
                double v = mandelbrot(point_x, point_y, COLOR_MAX_VALUE);

                int index = y * width + x;
                data[4 * index] = v;
                data[4 * index + 1] = v;
                data[4 * index + 2] = v;
                data[4 * index + 3] = COLOR_MAX_VALUE - v;
            }
        }
    }

    void Method(const FunctionCallbackInfo<Value> &args) {
        Local<Uint8ClampedArray> data = args[0].As<Uint8ClampedArray>();
        int width = args[1]->NumberValue();
        int height = args[2]->NumberValue();
        double dx = -2.0;
        double dy = -1.0;
        double scale = 1.0;
        unsigned char *ptr = (unsigned char *)data->Buffer()->GetContents().Data();
        execMandelbrot(ptr, width, height, dx, dy, scale);
    }

    void Init(Local<Object> exports) {
        NODE_SET_METHOD(exports, "execute", Method);
    }

    NODE_MODULE(addon, Init)
}
