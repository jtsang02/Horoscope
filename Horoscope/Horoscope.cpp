/*
 * Horoscope.cpp
 *
 *  Created on: Apr. 22, 2020
 *      Author: jtsan
 */

//	This program determines your horoscope based on your birthday based on non leap year days

#include <iostream>
#include <string>
using namespace std;

string lowerToUpper(string word){ //change first letter of string to uppercase
	char ch1 = word.at(0);
	if (islower(ch1)){ //check letter if lowercase
		word[0] = toupper(ch1); //change first character to uppercase
	}
	return word;
}

int find_firstDayOfMonth(string month){ //find day of year of first day of month (try making into switch)
	int firstDayOfMonth;

	//for non leap year
	if(month == "January"){
		firstDayOfMonth = 1;
	}
	else if(month == "February"){
		firstDayOfMonth = 32;
	}
	else if(month == "March"){
		firstDayOfMonth = 60;
	}
	else if(month == "April"){
		firstDayOfMonth = 91;
	}
	else if(month == "May"){
		firstDayOfMonth = 121;
	}
	else if(month == "June"){
		firstDayOfMonth = 151;
	}
	else if(month == "July"){
		firstDayOfMonth = 182;
	}
	else if(month == "August"){
		firstDayOfMonth = 213;
	}
	else if(month == "September"){
		firstDayOfMonth = 244;
	}
	else if(month == "October"){
		firstDayOfMonth = 274;
	}
	else if(month == "November"){
		firstDayOfMonth = 305;
	}
	else if(month == "December"){
		firstDayOfMonth = 335;
	}
	else{
		firstDayOfMonth = 0;// use this to check if correct month is entered
	}

return firstDayOfMonth;
}

string find_horoscope(int dayOfYear){ //find horoscope based on day of year
	string horoscope;

	if(dayOfYear >=19 && dayOfYear <=50){
		horoscope = "Aquarius";
	}
	else if(dayOfYear >=51 && dayOfYear <=79){
		horoscope = "Pisces";
	}
	else if(dayOfYear >=80 && dayOfYear <=110){
		horoscope = "Aries";
	}
	else if(dayOfYear >=111 && dayOfYear <=141){
		horoscope = "Taurus";
	}
	else if(dayOfYear >=142 && dayOfYear <=172){
		horoscope = "Gemini";
	}
	else if(dayOfYear >=173 && dayOfYear <=203){
		horoscope = "Cancer";
	}
	else if(dayOfYear >=204 && dayOfYear <=234){
		horoscope = "Leo";
	}
	else if(dayOfYear >=235 && dayOfYear <=265){
		horoscope = "Virgo";
	}
	else if(dayOfYear >=266 && dayOfYear <=295){
		horoscope = "Libra";
	}
	else if(dayOfYear >=296 && dayOfYear <=325){
		horoscope = "Scorpio";
	}
	else if(dayOfYear >=326 && dayOfYear <=355){
		horoscope = "Saggittarius";
	}
	else {//if ((dayOfYear >=355 && dayOfYear <=365) || (dayOfYear >=1 && dayOfYear <=18)){
		horoscope = "Capricorn";
	}

	return horoscope;
}

int main(){
cout << "Enter your birth month: " << endl;
string month;
getline(cin, month);

cout << "Enter the day of the month: " << endl;
int dayOfMonth;
cin >> dayOfMonth;

month = lowerToUpper(month); //make lowercase first letter input acceptable

if ((find_firstDayOfMonth(month) == 0) && (dayOfMonth < 0 || dayOfMonth > 31)){ //if both month and day are invalid
	cout << "invalid month and day" << endl;
	}

else if (find_firstDayOfMonth(month) == 0){ //if only month is invalid
	cout << "invalid month" << endl;
	}

else if (dayOfMonth < 0 || dayOfMonth > 31){ //if only day is invalid
	cout << "invalid day" << endl;
	}

else {	//if month and day are good inputs

	int firstDayOfMonth = find_firstDayOfMonth(month);
	int dayOfYear = firstDayOfMonth + dayOfMonth - 1;

	cout << "your horoscope is " << find_horoscope(dayOfYear) << endl;
}

return 0;
}


