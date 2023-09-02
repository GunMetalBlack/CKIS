string food = "Pizza";
string* ptr = &food;

// Output the value of food (Pizza)
cout << food << "\n";

// Output the memory address of food (0x6dfed4)
cout << &food << "\n";

// Access the memory address of food and output its value (Pizza)
cout << *ptr << "\n";

// Change the value of the pointer
*ptr = "Hamburger";

// Output the new value of the pointer (Hamburger)
cout << *ptr << "\n";

// Output the new value of the food variable (Hamburger)
cout << food << "\n";


// we used normal variables when we passed parameters to a function. 
//You can also pass a reference to the function. 
//This can be useful when you need to change the value of the arguments:
void swapNums(int &x, int &y) {
  int z = x;
  x = y;
  y = z;
}
