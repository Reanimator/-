#ifndef LIST_H
#define LIST_H
#include <iostream>

template <class T>
class SpisokMass
{  
   private:
	   int* ukozateli; //Массив указателей
	   T* inform; //Массив данных
	   int maxCount; //Рамер массива
	   int usagecolvo; //Количество элементов
	   int start; //Начало массива
	   int end; //Конец массива
   public:
	SpisokMass(int =1);
	SpisokMass(SpisokMass&);
	T get_element(int);
	~SpisokMass();
	void udalit_end();
	int get_next_element(int);
	void udalit_start();
	int get_start();
	void add_start(T);
	void add_end(T);
	bool is_end(int);
};
 
template <class T>
 SpisokMass<T>::SpisokMass<T>(int a)
{ 
	maxCount=a;
	usagecolvo= start= end =0;
	ukozateli= new int[maxCount];
	inform= new T[maxCount];
	for(int i=0; i<maxCount; i++)
	{ 
		ukozateli[i]=-1;
		inform[i]=T();
	}
}

template <class T>
SpisokMass<T>::SpisokMass<T>(SpisokMass<T>&a)
{
	maxCount=a.maxCount;
	usagecolvo=a.usagecolvo;
	start=a.start;
	end=a.end;
	ukozateli = new int[maxCount];
	inform = new T[maxCount];
	for (int i = 0; i<maxCount; i++)
	{
		ukozateli[i] = a.ukozateli[i];
		inform[i] = a.inform[i];
	}
}

template <class T>
SpisokMass<T>::~SpisokMass<T>()
{
	delete[] ukozateli;
	delete[] inform;
}

template <class T>
void SpisokMass<T>:: add_start(T a)
{
	if(usagecolvo==0)
	{ 
	   ukozateli[0]=-2;
	   start=0;
	   end=0;
	   inform[start]=a;

	}
	else
	{ 
		for(int i=0;i<maxCount;i++)
		{ 
			if(ukozateli[i]==-1)
			{
			  ukozateli[i]=start;
			  start=i;
			  inform[i]=a; 
			  break; 
			}
		}
	}
	usagecolvo++;
}

template <class T>
void SpisokMass<T>:: add_end(T a)
{
	if(usagecolvo==0)
	{ 
	   ukozateli[0]=-2;
	   start=0;
	   end=0;
	   inform[end]=a;
	}
	else
	{ 
		for(int i=0;i<maxCount;i++)
		{ 
			if(ukozateli[i]==-1)
			{
			  ukozateli[end]=i;
			  end=i;
			  inform[i]=a; 
			  ukozateli[i]=-2;
			  break; 
			}
		}
	}usagecolvo++;
}

template <class T>
void SpisokMass<T>:: udalit_start()
{
	int S=start;
	start=ukozateli[start];
	ukozateli[S]=-1;
	usagecolvo--;
}

template <class T>
void SpisokMass<T>:: udalit_end()
{
	for(int i=0; i<maxCount; i++)
	{
	  if(ukozateli[i]==end)
	  {
	    ukozateli[end]=-1;
		ukozateli[i]=-2;
		end=i;
		usagecolvo--;
		return;
	  }
	}
}

template <class T>
int SpisokMass<T>:: get_start()
{
	return start;
}

template <class T>
int SpisokMass<T>:: get_next_element(int a)
{
    return ukozateli[a];
}

template <class T>
bool SpisokMass<T>:: is_end(int a)
{
	if(a==-2)
	{ return true; }
	return false;
}

template <class T>
T SpisokMass<T>:: get_element(int end)
{
	return inform[end];
}

#endif 
