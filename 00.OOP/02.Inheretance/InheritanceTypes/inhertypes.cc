#include <iostream>

class geometric
{
    protected:
        float dimension1;
        float dimension2;
    public:
        geometric() : dimension1(0), dimension2(0) {
            std::cout << "Default constructor of base class\n";
        }
        geometric(float dim) : dimension1(dim), dimension2(dim) {
            std::cout << "1-parameter constructor of base class\n";
        }		
        geometric(float dim1, float dim2) : dimension1(dim1), dimension2(dim2) {
            std::cout << "2-parameter constructor of base class\n";
        }
        
        void set2Dim(float dim1, float dim2) {
            dimension1 = dim1;
            dimension2 = dim2;
            std::cout << "2-parameter setter of base class\n";
        }
        void set1Dim(float dim) {
            dimension1 = dim;
            dimension2 = dim;
            std::cout << "1-parameter setter of base class\n";
        }
        float getDim1() { return dimension1; }
        float getDim2() { return dimension2; }
        virtual float getArea() {
            std::cout << "Area Method of parent class\n";
            return 0.0f;  // Assuming a default return value, as the base class doesn't define specific behavior
        }
        virtual ~geometric() {
            std::cout << "Destructor of base class\n";
        }
};

class triangle : public geometric
{
    public:
        triangle() : geometric() {
            std::cout << "Default constructor of child class (triangle)\n";
        }
        triangle(float dim) : geometric(dim) {
            std::cout << "1-parameter constructor of child class (triangle)\n";
        }
        triangle(float dim1, float dim2) : geometric(dim1, dim2) {
            std::cout << "2-parameter constructor of child class (triangle)\n";
        }
        
        float getArea() override {
            std::cout << "Area Method of triangle class\n";
            return 0.5f * dimension1 * dimension2;
        }	
		
        ~triangle() {
            std::cout << "Destructor of child class (triangle)\n";
        }
}; 

class rectangle : public geometric
{
    public:
        rectangle() : geometric() {
            std::cout << "Default constructor of child class (rectangle)\n";
        }
      
        rectangle(float dim1, float dim2) : geometric(dim1, dim2) {
            std::cout << "2-parameter constructor of child class (rectangle)\n";
        }
        
        float getArea() override {
            std::cout << "Area Method of rectangle class\n";
            return dimension1 * dimension2;
        }	
		
        ~rectangle() {
            std::cout << "Destructor of child class (rectangle)\n";
        }
};

class square : private rectangle
{
    public:
        square() : rectangle() {
            std::cout << "Default constructor of grandchild class (square)\n";
        }
        square(float dim) : rectangle(dim, dim) {
            std::cout << "1-parameter constructor of grandchild class (square)\n";
        }
        void setDim(float dim) {
            std::cout << "Setter of square grandchild\n";
            dimension1 = dimension2 = dim;
        }
        float getDim() {
            return dimension1;
        }
        float getArea() {
        	return dimension1*dimension1;
        }
        ~square() {
            std::cout << "Destructor of grandchild class (square)\n";
        }
}; 

int main() {
    triangle t(5.0f, 10.0f);
    std::cout << "Triangle Area: " << t.getArea() << std::endl;

    rectangle r(4.0f, 6.0f);
    std::cout << "Rectangle Area: " << r.getArea() << std::endl;

    square s(5.0f);
    std::cout << "Square Area: " << s.getArea() << std::endl; // This line will not compile due to private inheritance

    return 0;
}

