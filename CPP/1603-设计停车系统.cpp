#include <iostream>
using namespace std;
class ParkingSystem{
	public:
		ParkingSystem(int big,int medium,int small) {
			this->big=this->bleft=big;
			this->small=this->sleft=small;
			this->medium=this->mleft=medium;
		};

		bool addCar(int carType){
			bool ans;
			switch(carType){
				case 1: 
					ans=sleft>0;
					if(sleft>0) sleft--;
					break;
				case 2: 
					ans=mleft>0;
					if(mleft>0) mleft--;
					break;
				case 3: 
					ans=bleft>0;
					if(bleft>0) bleft--;
					break;
				default:
					ans=false;
					break;
			}
			return ans;
		};
	private:
		int small,medium,big;
		int sleft,bleft,mleft;
};
