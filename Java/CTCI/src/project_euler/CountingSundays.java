package project_euler;

public class CountingSundays {

	static boolean isLeapYear(int year) {
		if (year % 100 == 0) {
			return (year % 400 == 0);
		}
		return (year % 4 == 0);
	}
	
	static int getMonthLength(int month, int year) {
		switch(month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;
		case 4:
		case 6:
		case 9:
		case 11:
			return 30;
		case 2:
			return isLeapYear(year) ? 29: 28;
		default:
			System.out.println("bad input");
			return -1;
		}
	}
	
	//(1 Jan 1901 to 31 Dec 2000)
	static int numSundaysOnFirst() {
		

		  int n = 0;
		  int dow = 2;
		  int[] months_lengths = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

		  for (int y = 1901; y <= 2000; y++) {

			  months_lengths[1] = ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) ? 29 : 28;

		    for (int month = 0; month < 12; month++) {
		      dow += months_lengths[month] % 7;
		      if (dow % 7 == 0) {
		        n++;
		      }
		    }
		  }
		return n;
	}
	public static void main(String[] args) {
		System.out.println(numSundaysOnFirst());

	}

}
