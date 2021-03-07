#include <iostream>
#include <ctype.h>
#include <cctype>

using namespace std;

class User
{
private:
	char userType;	// if type is 'Y' --> Student else Faculty/Staff member
	int columnTime;
	bool userOccupied;

public:
	User()
	{
		setUserType('Y');
		setTime(-1);
		setUserOccupied(false);
	}

	void setUserType(char a)
	{
		userType = a;
	}
	void setTime(int a)
	{
		columnTime = a;
	}
	void setUserOccupied(bool a)
	{
		userOccupied = a;
	}

	char getUserType()
	{
		return userType;
	}
	int getTime()
	{
		return columnTime;
	}
	bool getIsOccupied()
	{
		return userOccupied;
	}
};
class Parking : public User
{
private:
	User B[15][12];
	User M[10][12];
	User S[5][12];

	int totalSpots[3] = {15 * 12, 10 * 12, 5 * 12};	// parking B, parking M, parking S
	int occupiedSpots[3];	// parking B, parking M, parking S
	int emptySpots[3];	// parking B, parking M, parking S
	int rejectedRequests[3];	// parking B, parking M, parking S

	int hourlyB[12];
	int hourlyM[12];
	int hourlyS[12];

public:
	Parking()
	{
		updateParking(true);
	}

	void updateParking(bool initialize)
	{
		
		// updating OccupiedSpots array
		int count = 0;
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 12; j++)
			{
				if (B[i][j].getIsOccupied())
					count++;
			}
		}

		occupiedSpots[0] = count;
		count = 0;
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 12; j++)
			{
				if (M[i][j].getIsOccupied())
					count++;
			}
		}

		occupiedSpots[1] = count;
		count = 0;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 12; j++)
			{
				if (S[i][j].getIsOccupied())
					count++;
			}
		}

		occupiedSpots[2] = count;
		count = 0;

		for (int i = 0; i < 3; i++)
		{
			emptySpots[i] = totalSpots[i] - occupiedSpots[i];
		}

		if (initialize)
		{
			for (int i = 0; i < 3; i++)
			{
				rejectedRequests[i] = 0;
			}

			for (int i = 0; i < 12; i++)
			{
				hourlyB[i] = 0;
				hourlyM[i] = 0;
				hourlyS[i] = 0;
			}
		}
		else
		{
			// update hourly only , rejected requests will execute based on the user scenario
			
			for (int i = 0; i < 12; i++)
			{
				count = 0;
				for (int j = 0; j < 15; j++)
				{
					if (B[j][i].getIsOccupied())
						count++;
				}
				hourlyB[i] = count;
			}

			for (int i = 0; i < 12; i++)
			{
				count = 0;
				for (int j = 0; j < 10; j++)
				{
					if (M[j][i].getIsOccupied())
						count++;
				}
				hourlyM[i] = count;
			}

			for (int i = 0; i < 12; i++)
			{
				count = 0;
				for (int j = 0; j < 5; j++)
				{
					if (S[j][i].getIsOccupied())
						count++;
				}
				hourlyS[i] = count;
			}
		}
	}

	void displayParking()
	{
		cout << "=====================================================================================================================" << endl;
		cout << "Parking Area B\t\tTotal Spots: " << totalSpots[0] << "\tEmpty Spots: " << emptySpots[0] << "\tOccupiedSpots: " << occupiedSpots[0] << "\tRejected Requests: " << rejectedRequests[0] << endl;
		cout << "=====================================================================================================================" << endl;
		cout << endl;
		cout << "9 am\t10 am\t11 am\t12 pm\t1 pm\t2 pm\t3 pm\t4 pm\t5 pm\t6 pm\t 7 pm\t8 pm" << endl;
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 12; j++)
			{
				if (B[i][j].getIsOccupied() && i == 0)	//for faculty display 
					cout << "[XXX]\t";
				else if (B[i][j].getIsOccupied() == false && i == 0)	//for faculty display
					cout << "[---]\t";
				else if (B[i][j].getIsOccupied() && i != 0)
					cout << "[ X ]\t";
				else
					cout << "[ - ]\t";
			}
			cout << endl;
		}
		cout << endl;

		cout << "=====================================================================================================================" << endl;
		cout << "Parking Area M\t\tTotal Spots: " << totalSpots[1] << "\tEmpty Spots: " << emptySpots[1] << "\tOccupiedSpots: " << occupiedSpots[1] << "\tRejected Requests: " << rejectedRequests[1] << endl;
		cout << "=====================================================================================================================" << endl;
		cout << endl;
		cout << "9 am\t10 am\t11 am\t12 pm\t1 pm\t2 pm\t3 pm\t4 pm\t5 pm\t6 pm\t 7 pm\t8 pm" << endl;
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 12; j++)
			{
				if (M[i][j].getIsOccupied() && i == 0)	//for faculty display 
					cout << "[XXX]\t";
				else if (M[i][j].getIsOccupied() == false && i == 0)	//for faculty display
					cout << "[---]\t";
				else if (M[i][j].getIsOccupied() && i != 0)
					cout << "[ X ]\t";
				else
					cout << "[ - ]\t";
			}
			cout << endl;
		}
		cout << endl;

		cout << "=====================================================================================================================" << endl;
		cout << "Parking Area S\t\tTotal Spots: " << totalSpots[2] << "\t\tEmpty Spots: " << emptySpots[2] << "\t\tOccupiedSpots: " << occupiedSpots[2] << "\tRejected Requests: " << rejectedRequests[2] << endl;
		cout << "=====================================================================================================================" << endl;
		cout << endl;
		cout << "9 am\t10 am\t11 am\t12 pm\t1 pm\t2 pm\t3 pm\t4 pm\t5 pm\t6 pm\t 7 pm\t8 pm" << endl;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 12; j++)
			{
				if (S[i][j].getIsOccupied() && i == 0)	//for faculty display 
					cout << "[XXX]\t";
				else if (S[i][j].getIsOccupied() == false && i == 0)	//for faculty display
					cout << "[---]\t";
				else if (S[i][j].getIsOccupied() && i != 0)
					cout << "[ X ]\t";
				else
					cout << "[ - ]\t";
			}
			cout << endl;
		}
		cout << endl << endl;

	}

	void displayHourlyInfo()
	{
		cout << "=============================================================================================================" << endl;
		cout << "\t\t\t\t\tHourly Parked Cars" << endl;
		cout << "=============================================================================================================" << endl;

		cout << "Parking Area\t9 am\t10 am\t11 am\t12 pm\t1 pm\t2 pm\t3 pm\t4 pm\t5 pm\t6 pm\t 7 pm\t8 pm" << endl;
		cout << "    B\t\t ";
		for (int i = 0; i < 12; i++)
		{
			cout << hourlyB[i] << "\t ";
		}
		cout << endl;

		cout << "    M\t\t ";
		for (int i = 0; i < 12; i++)
		{
			cout << hourlyM[i] << "\t ";
		}
		cout << endl;

		cout << "    S\t\t ";
		for (int i = 0; i < 12; i++)
		{
			cout << hourlyS[i] << "\t ";
		}
		cout << endl;
		cout << endl << endl;
	}

	int time2Col(int a)
	{
		if (a >= 9 && a <= 12)
			a = a - 9;
		else
			a = a + 3;

		return a;
	}

	bool isSpaceAvailable(char area, char type, int time)
	{
		time = time2Col(time);
		if (type == 'n')	// not a student, faculty member
		{
			// check for 1st row only
			if (area == 'b')
			{
				if (B[0][time].getIsOccupied())
					return false;
				else
					return true;
			}
			else if (area == 'm')
			{
				if (M[0][time].getIsOccupied())
					return false;
				else
					return true;
			}
			else
			{
				if (S[0][time].getIsOccupied())
					return false;
				else
					return true;
			}
		}
		else	// is a student
		{
			if (area == 'b')
			{
				for (int i = 1; i < 15; i++)
				{
					if (B[i][time].getIsOccupied() == false)
						return true;
				}
				return false;
			}
			else if (area == 'm')
			{
				for (int i = 1; i < 10; i++)
				{
					if (M[i][time].getIsOccupied() == false)
						return true;
				}
				return false;
			}
			else
			{
				for (int i = 1; i < 5; i++)
				{
					if (S[i][time].getIsOccupied() == false)
						return true;
				}
				return false;
			}
		}
	}

	void rejectRequest(char area)
	{
		if (area == 'b')
			rejectedRequests[0]++;
		else if (area == 'm')
			rejectedRequests[1]++;
		else
			rejectedRequests[2]++;
	}

	void parkCar(char area, char type, int time)
	{
		int t = time2Col(time);
		if (type == 'n')	// not a student
		{
			if (area == 'b')
			{
				B[0][t].setUserOccupied(true);
				B[0][t].setUserType(type);
				B[0][t].setTime(time);
			}
			else if (area == 'm')
			{
				M[0][t].setUserOccupied(true);
				M[0][t].setUserType(type);
				M[0][t].setTime(time);
			}
			else
			{
				S[0][t].setUserOccupied(true);
				S[0][t].setUserType(type);
				S[0][t].setTime(time);
			}
		}
		else	// is a student
		{
			if (area == 'b')
			{
				for (int i = 1; i < 15; i++)
				{
					if (B[i][t].getIsOccupied() == false)
					{
						B[i][t].setUserOccupied(true);
						B[i][t].setUserType(type);
						B[i][t].setTime(time);
						break;
					}
				}
			}
			else if (area == 'm')
			{
				for (int i = 1; i < 10; i++)
				{
					if (M[i][t].getIsOccupied() == false)
					{
						M[i][t].setUserOccupied(true);
						M[i][t].setUserType(type);
						M[i][t].setTime(time);
						break;
					}
				}
			}
			else
			{
				for (int i = 1; i < 5; i++)
				{
					if (S[i][t].getIsOccupied() == false)
					{
						S[i][t].setUserOccupied(true);
						S[i][t].setUserType(type);
						S[i][t].setTime(time);
						break;
					}
				}
			}
		}
	}

};

char userInputArea()
{
	char a;
	while (true)
	{
		cout << "Select a parking area[B, M, S]: ";
		cin >> a;
		a = tolower(a);

		if (a == 'b' || a == 'm' || a == 's')
			break;
	}
	return a;
}
char userInputType()
{
	char a;
	while (true)
	{
		cout << "Are you a student[Y/N]: ";
		cin >> a;
		a = tolower(a);

		if (a == 'y' || a == 'n')
			break;
	}
	return a;
}
int userInputTime()
{
	int a = 0;
	int toSelectFrom[12] = { 9, 10, 11, 12, 1, 2, 3, 4, 5, 6, 7, 8 };
	while (true)
	{
		int flag = 0;
		cout << "Till what time do you wish to park[9 a.m --> 8 p.m]: ";
		cin >> a;

		for (int i = 0; i < 12; i++)
		{
			if (a == toSelectFrom[i])
			{
				flag = 1;
				break;
			}
		}

		if (flag == 1)
		{
			break;
		}
	}
	return a;
}
char* getOtherAreas(char current_area)
{
	char areas[3] = { 'b', 'm', 's' };
	char otherAreas[2] = {' ', ' '};
	int a = 0;
	for (int i = 0; i < 3; i++)
	{
		if (current_area != areas[i])
		{
			otherAreas[a] = areas[i];
			a++;
		}
	}

	return otherAreas;
}

void parkingSystem()
{
	Parking p;

	while (true)
	{
		p.updateParking(false);
		p.displayParking();
		p.displayHourlyInfo();

		char area = userInputArea();
		char type = userInputType();
		int userTime = userInputTime();

		//cout << "Area selected: " << area << "\tType selected: " << type << "\tTime selected: " << userTime << endl;

		bool availableSpace = p.isSpaceAvailable(area, type, userTime);
		char* other_areas = getOtherAreas(area);
		char area2 = other_areas[0];
		char area3 = other_areas[1];

		if (p.isSpaceAvailable(area, type, userTime))	// if space is available based on user entry
		{
			//park car
			cout << "Please park your car at column " << p.time2Col(userTime) << " in Area " << toupper(area) << " ..." << endl;
			p.parkCar(area, type, userTime);
		}
		else	// check other parking areas
		{
			// checking in 2nd parking area
			if (p.isSpaceAvailable(area2, type, userTime))
			{
				cout << "Parking Area " << toupper(area) << " is Full at " << userTime << ", Empty Space found at parking area " << toupper(area2) << ", Would you like to park[Y/N]: ";
				char response;
				while (true)
				{
					cin >> response;
					response = tolower(response);
					if (response == 'y' || response == 'n')
						break;
				}

				if (response == 'y')
				{
					//park car in area2
					cout << "Please park your car at column " << p.time2Col(userTime) << " in Area "<<toupper(area2)<<" ..." << endl;
					p.parkCar(area2, type, userTime);
				}
				else	//reject request, which means they dont want to park anymore
				{
					cout << "Request Rejected..." << endl;
					p.rejectRequest(area);
				}

			}
			else	// check in 3rd parking area
			{
				if (p.isSpaceAvailable(area3, type, userTime))
				{
					cout<<"Parking Area " << toupper(area) << " is Full at " << userTime << ", Empty Space found at parking area " << toupper(area3) << ", Would you like to park[Y/N]: ";
					char resp;
					while (true)
					{
						cin >> resp;
						resp = tolower(resp);
						if (resp == 'y' || resp == 'n')
							break;
					}

					if (resp == 'y' || resp == 'n')
					{
						//park car in area3
						cout << "Please park your car at column " << p.time2Col(userTime) << " in Area " << toupper(area3) << " ..." << endl;
						p.parkCar(area3, type, userTime);
					}
					else
					{
						//reject request.
						cout << "Request Rejected..." << endl;
						p.rejectRequest(area2);
					}
				}
				else
				{
					cout << "Request Rejected..." << endl;
					p.rejectRequest(area3);
				}
			}
		}

		char exit;
		while (true)
		{
			cout << "Exit program [Y/N]: ";
			cin >> exit;
			exit = tolower(exit);

			if (exit == 'y' || exit == 'n')
				break;
		}

		if (exit == 'y')
		{
			cout << "Exiting parking system..." << endl;
			break;
		}
		else
		{
			system("CLS");
		}
	}

}

int main()
{
	parkingSystem();
}