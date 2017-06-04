#include "ListMass.h"
#include <iostream>
#include <direct.h>
#include <string>

int main()
{
   SpisokMass<std::string> a(200);
   setlocale(LC_ALL, "RUSSIAN");

   a.addPath();
   for(int i=a.get_start();!a.is_end(i);i=a.get_next_element(i))
   {
	   std:: cout<<a.get_element(i)<<" ";
   }

   std:: cin.get();
};