#include <iostream>

class complex {
private:
    int real;
    int img;
    
public:
    // Default Constructor
    complex() 
    {
    	real=0;
        img=0;
    }

    // Constructor with one parameter
    complex(int num) 
    {
    	real=num;
        img=num;
    }
    // Constructor with two parameters
    complex(int r, int i) : real(r), img(i) {}

    // Setters
    void setReal(int real) { this->real = real; }
    void setImg(int img) { this->img = img; }
    void setComplex(int real, int img) { this->real = real; this->img = img; }

    // Getters
    int getReal() const { return real; } //does not modify in class member data
    int getImg() const { return img; }

    // Print complex number
    void printComplex() const {
        if (real != 0 && img > 0) {
            std::cout << "Complex number: " << real << " + " << img << "i" << std::endl;
        } else if (real != 0 && img == 0) {
            std::cout << "Complex number: " << real << std::endl;
        } else if (img < 0) {
            std::cout << "Complex number: " << real << " - " << std::abs(img) << "i" << std::endl;
        } else if (real == 0) {
            std::cout << "Complex number: " << img << "i" << std::endl;
        }
    }
    
     complex addComplex(complex complexObj)
        {
        	complex temp;
        	temp.real=this->real+complexObj.real;
        	temp.img=this->img+complexObj.img;
        	return temp;
        }
        
        complex subComplex(complex complexObj)
        {
        	complex temp;
        	temp.real=this->real-complexObj.real;
        	temp.img=this->img-complexObj.img;
        	return temp;
        }

/*
    // Add two complex numbers
    complex addComplex(const complex& complexObj) const {
        return complex(real + complexObj.real, img + complexObj.img);
    }

    // Subtract two complex numbers
    complex subComplex(const complex& complexObj) const {
        return complex(real - complexObj.real, img - complexObj.img);
    }*/
};

int main() {
    complex c1(7, 8);
    c1.printComplex();

    std::cout << "-------------------------------------------\n";

    complex c2(5);
    c2.printComplex();

    std::cout << "-------------------------------------------\n";

    complex c3;
    c3.setComplex(7, 8);
    c3.printComplex();

    std::cout << "-------------------------------------------\n";

    complex result;
    result = c1.subComplex(c3);
    result.printComplex();

    std::cout << "-------------------------------------------\n";

    return 0;
}

