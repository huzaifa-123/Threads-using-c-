#include <iostream>
#include<pthread.h>
#include <unistd.h>
#include<string>

using namespace std;
void* input(void*)
{
        int str;
        cout << "Enter a string: ";
        cin >> str;

}

// reverse thread function
void* reverse(void*)
{

    
        cout << "Reversed string: ";
        for (int i = 0; i < str.length(); i++)
            cout << str[str.length() - i - 1];
        cout << endl;
    
    return NULL;
}

// capital thread function
void* caps(void*)
{
    
        cout << "Capitalized string: ";
        for (int i = 0; i < str.length(); i++)
            cout << (char)toupper(str[i]);
        cout << endl;
    
    return NULL;

}

// shift thread function
void* shift(void*)
{
    
    
        cout << "Shifted string: ";
        for (int i = 0; i < str.length(); i++)
            cout << (char)(str[i] + 2);
        cout << endl;
    return NULL;

}

int main()
{
	// create the input thread
	pthread_t t1;
	pthread_create(&t1, NULL, input, NULL);

	// wait for input thread to finish
	pthread_join(t1, NULL);

	// create the reverse, capital, and shift threads
	pthread_t t2, t3, t4;
	pthread_create(&t2, NULL, reverse, NULL);
	pthread_create(&t3, NULL, caps, NULL);
	pthread_create(&t4, NULL, shift, NULL);
	cout<<endl;
	// wait for all threads to finish
	pthread_join(t2, NULL);
	cout<<endl;
	pthread_join(t3, NULL);
	cout<<endl;
	pthread_join(t4, NULL);

}
