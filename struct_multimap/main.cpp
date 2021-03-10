#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <iomanip>
#include <set>
#include <ctime>
#include <unordered_map>
#include <map>

using namespace std;

struct l
{
	int value = 0 ;
	l * next	= NULL;
	l * parent 	= NULL;
//	unordered_multimap<int,l*>::iterator it;
	multimap<int,l*>::iterator it;
	l(int x)
	{
		value =x;
	}
};

struct r
{
	int value = 0 ;
	r * next	= NULL;
	r * parent 	= NULL;
	r(int x)
	{
		value =x;
	}
//	unordered_multimap<int,r*>::iterator it;
	multimap<int,r*>::iterator it;
};



struct ma
{
	int value = 0;
	l * left 	= NULL;
	r * right	= NULL;
	l * l_end 	= NULL;
	r * r_end 	= NULL;
	bool init 	= false;
	bool mid 	= false;

};

int main ()
{
//	unique_ptr<l> a;
//	unique_ptr<r> b;
	cout<<fixed;
//	unordered_multimap <int , l* > left  ;
//	unordered_multimap <int , r* > right ;
	multimap <int , l* > left  ;
	multimap <int , r* > right ;
//	unordered_multimap <int , l* >::iterator l_it;
//	unordered_multimap <int , r* >::iterator r_it;
	float times=0;
	int n = 0;
	cin >> n;
	char x ;
	int y ;
	ma midian;
	bool flag1 = true ;
	bool flag2 = true ;

	for(int i = 0 ; i < n ; i ++)
	{
		cout<<"started>-1";
		const clock_t begin_time = clock();
		cout<<"started>-1";
		cin >> x ;
		cout<<"started>-1 "<<x<<endl;
		if(x=='a')
			cout<<"a7a"<<endl;
		cin >> y ;
		cout<<"started>-100000 "<<y <<endl;
		cout<<"__________________"<<endl;
		if(x=='a')
		{
			cout<<"started>-2";
			if(!midian.init)
			{
				midian.value 	= y;
				midian.init 	= true;
				midian.mid		= true;
//				continue;
			}
			else
			{
				if(y < (midian.value))
				{
					cout<<"started>0";
					// add element to the left
					// check if the element is less than the last element then we add it to the end of the loop
					// if not check is this element is already exist then we add it by shifting the already found
					// use binary search
					if(midian.l_end)
					{cout<<"started>1";
						flag1 = false;
						if(midian.l_end->value>=y)
						{
							cout<<"started>2";
							flag1 = true ;
							// add element to the end of the left side
							l * b = new l (y);
							b->parent=midian.l_end;
							midian.l_end->next=b;
							midian.l_end= b;
							// add element to the map
							const clock_t begin_time1 = clock();
							pair <int,l*> my_pair (y,b);
//							auto x = left.insert(midian.l_end->it,my_pair);
							auto x = left.insert(my_pair);
							float current1 = float( clock () - begin_time1 ) /  CLOCKS_PER_SEC;
//							times = times + current;
							cout<<" Initialize ** Time >> "<<current1 <<endl;
							// save it of the new insertion in the new left element
							b->it=x;
						}
						if(!flag1)
						{
							auto x = left.find(y);
							if(x!=left.end())
							{
								// add element to the struct
								l * b = x->second;
								l * c = new l (y);
								c->next		= b->next;
								c->parent 	= b;
								b->next   	= c ;
								// add element to the map
								pair <int,l*> my_pair (y,c);
//								auto s = left.insert(b->it,my_pair);
								auto s = left.insert(my_pair);
								// save it of the new insertion in the new left element
								c->it=s;
							}
							else
							{

								// ensure that it is not the biggest number in this side
								if(midian.left->value<y)
								{
									l * b = new l (y);
									b->next = midian.left;
									midian.left->parent= b;
									// add element to the map
									pair <int,l*> my_pair (y,b);
//									auto s =left.insert(midian.left->it,my_pair);
									auto s = left.insert(my_pair);
									b->it=s;
									midian.left=b;
								}
								// element is new and not in the list
								else
								{
									for(auto x : left)
									{
										printf("><><>>> %d " , x.second->value);
										if(x.first > y)
										{
											l * b = (x.second);
											l * c = new l (y);
											c->next		= b->next;
											c->parent 	= b;
											b->next   	= c ;
											pair <int,l*> my_pair (y,c);
//											auto s = left.insert(b->it,my_pair);
											auto s = left.insert(my_pair);
											// save it of the new insertion in the new left element
											c->it=s;
											break;
										}

									}
								}
							}


						}

					}
					else {
						l * c = new l (y);
						midian.left	= c;
						midian.l_end= c;
						pair <int,l*> my_pair (y,c);
						auto s = left.insert(my_pair);
						// save it of the new insertion in the new left element
						c->it=s;
						// add element to the left side of the midian
						// add element to the last element of the midian
					}
				}
				else if(y>midian.value)
				{
					// add element to the right
				}
				else // y == midian
				{
					// check if the case is mid then we need to add this element to the left and shift the midian to the right
					// if the case is not mid then the mid will be that value
				}
			}

		}
		else if (x=='r')
		{

		}


		cout<<"done"<<i<<endl;
		for(auto s : left)
		{
			cout<<">> " << s.second->value<<endl;
		}

		float current = float( clock () - begin_time ) /  CLOCKS_PER_SEC;
		times = times + current;
		cout<< ">> " <<x<<" Initialize ** Time >> "<<current << "\t Total = "<< times <<endl;
	}
	auto s = midian.left;
	while(s)
	{
		cout<<" %% >> " <<s->value<<endl;
		s=s->next;
	}
//	cout<<""
	return 0 ;
}
