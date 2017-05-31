#include "ListMass.h"
#include <iostream>

int main()
{
   SpisokMass<int> a(200);
   a.add_start(35);
   a.add_start(41);
   a.add_end(224);
   a.udalit_end();
   a.add_end(351);
   a.add_end(1111);
   a.udalit_end();
   a.add_end(55231);
   a.add_start(12113);
   a.add_start(12113);
   a.add_start(12113);
   a.add_start(12113);
   a.add_start(12113);
   a.add_start(12113);
   a.add_start(12113);
   a.add_start(12113);
   a.add_start(12113);
   a.add_end(55231);
   a.add_start(55231);
   a.add_start(55231);
   a.add_end(55231);
   a.udalit_end();

   for(int i=a.get_start();!a.is_end(i);i=a.get_next_element(i))
   {
	   std:: cout<<a.get_element(i)<<" ";
   }

   std:: cin.get();
};