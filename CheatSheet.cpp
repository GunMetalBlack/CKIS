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


// Eninge functions
// stuff
    render(map, MyPlayer);
    string input;
    cout << "What do you want to do?";
    cin >> input;
    if (input[0] == '/')
    {
        // Other Commands
    }
    else
    {
        for (int i = 0; i < input.length(); i++)
        {
            if ((input[i] == 'w') && MyPlayer.y > 0)
            {
                MyPlayer.message = "moved north";
                MyPlayer.y = MyPlayer.y - 1;
            }
            else if (input[i] == 's' && MyPlayer.y < 9)
            {
                MyPlayer.message = "moved south";
                MyPlayer.y = MyPlayer.y + 1;
            }
            else if (input[0] == 'a' && MyPlayer.x > 0)
            {
                MyPlayer.message = "moved west";
                MyPlayer.x = MyPlayer.x - 1;
            }
            else if (input[0] == 'd' && MyPlayer.x < 19)
            {
                MyPlayer.message = "moved east";
                MyPlayer.x = MyPlayer.x + 1;
            }
            else
            {
                MyPlayer.message = "invalid input";
            }
        }