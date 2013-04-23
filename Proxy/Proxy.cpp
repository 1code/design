#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Image {
public:
    virtual void displayImage() = 0;
};

class RealImage : Image {
public:
    RealImage(string filename) {
        _filename = filename;
        loadImageFromDisk();
    }

    void displayImage() {
        cout << "displaying: " << _filename << endl; 
    }

private:
    void loadImageFromDisk() {
        cout << "loading: " << _filename << endl;
    } 

    string _filename;
};

class ProxyImage : Image {
public:
    ProxyImage(string filename) {
        _filename = filename;
        _image = nullptr;
    }

    void displayImage() {
        if (_image == nullptr) {
            _image = unique_ptr<RealImage>(new RealImage(_filename));
        }

        _image->displayImage();
    }

private:
    string _filename;
    unique_ptr<RealImage> _image;
};


int main() {
    ProxyImage image1("HiRes_10MB_Photo1");
    ProxyImage image2("HiRes_10MB_Photo2");

    image1.displayImage();
    image1.displayImage();
    image2.displayImage();
    image2.displayImage();
    image1.displayImage();

    return 0;
}
