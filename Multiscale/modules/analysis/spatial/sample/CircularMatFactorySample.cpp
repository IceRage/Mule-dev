#include "multiscale/analysis/spatial/factory/CircularMatFactory.hpp"

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace multiscale::analysis;
using namespace std;

// Main function

int main() {
    CircularMatFactory factory;

    Mat image = factory.createFromViewerImage("/home/ovidiu/Repositories/git/multiscale/Multiscale/data/test/circular.png");

    namedWindow("Test", WINDOW_NORMAL);
    imshow("Test", image);

    cout << "Maximum colour bar intensity: "
         << factory.maxColourBarIntensityFromViewerImage("/home/ovidiu/Repositories/git/multiscale/Multiscale/data/test/circular.png")
         << endl;

    waitKey(0);

    return 0;
}