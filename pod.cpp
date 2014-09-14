#include"pod.h"
#include<iostream>
#include <set>
#include <algorithm>
inline int GetMinSet(std::set<int> &a);
void elem::set_elem(int val){
  value = val;
}
void elem::set_next(elem &val){
  next=&val;
}
int elem::get_elem(){
  return value;
}
elem* elem::get_next(){
  return next;
}

proc::proc(){
  std::vector<int> tmp ;
  int size;
  std::cout<<"\nВведит число элементов в подстановке ";
  std::cin>>size;
  Podstan.resize(size);
  std::cout<<"\nВедите <значение> <след. значение> для "<<size<<" элементов :\n";
  for(int i=0;i<size;++i){
    int a,b;
    std::cin>>a>>b;
    Podstan[i].set_elem(a);
    tmp.push_back(b); 
  }
  for(int i=0;i<tmp.size();++i){
     Podstan[i].set_next(Podstan[get_ind(tmp[i])]);
  }
  show();
  
  
}
int proc::get_ind(int val){
  for (int i=0;i<Podstan.size();++i){
    if(Podstan[i].get_elem()==val)return i;
  }
  return -1;
}
   
void proc::show(){
  std::cout<<"\n( ";
    for(int i=0;i<Podstan.size();++i){
     std::cout<<Podstan[i].get_elem()<<" ";
  }
      std::cout<<")\n( ";
      for(int i=0;i<Podstan.size();++i){
     std::cout<<Podstan[i].get_next()->get_elem()<<" ";
  }
  std::cout<<")  ==  ";
  D=decrement();
  std::cout<<"\nD(П)= "<<D;
  std::cout<<"\nI(П)= "<<inversy();
  if(chetnost())std::cout<<"\nT(П)= "<<chetnost()<<" не четная";
  else{std::cout<<"\nT(П)= "<<chetnost()<<" четная";
  }
    
  std::cout<<"\n";
}

int proc::decrement(){
  return Podstan.size()-free_loops();
}

int proc::free_loops(){
  int frlp=0;
  std::set<int> floop;
  std::set<int>tmp;
  for(int i=0;i<Podstan.size();++i){
    tmp.insert(Podstan[i].get_elem());
  }
   int min =0;
 int firstmin=0;
 bool menu=true;
  do{
    
   if( min==0) {
      min=GetMinSet(tmp);
      std::cout<<"( "<<min;
        firstmin=min;
    //values.erase(min);
  }
 // std::cout<<min;

    for(int j=0;j<Podstan.size();j++){
	if (min==Podstan[j].get_elem()){
	        tmp.erase(min);
	   min=Podstan[j].get_next()->get_elem();
	     if(min!=firstmin)std::cout<<" "<<min;
	}
	}

       if(min==firstmin){
	 min=0;
	 frlp++;
	 std::cout<<")";
	  if(tmp.size()==0)menu=false;
	 //break;
       }

   // values.erase(min);
}while(menu);
  return frlp;
}

int proc::inversy(){
  int invent=0;
  for(int i=0;i<Podstan.size();++i){
    for(int j=0;j<Podstan.size();++j){
      if(Podstan[i].get_next()->get_elem()>Podstan[j].get_next()->get_elem() && j>i)invent++;
    }
  }
  return invent;
}

bool proc::chetnost(){
  return D%2;
}

int GetMinSet(std::set<int> &a){
  return *std::min_element(a.begin(), a.end());
}