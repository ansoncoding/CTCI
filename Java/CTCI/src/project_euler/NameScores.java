package project_euler;
import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Arrays;
import java.util.Scanner;
public class NameScores {
	
	
	static String[] names;
	final static String fileName = "D:\\Programming\\Interview_Practice\\CTCI\\Java\\CTCI\\src\\project_euler\\022_input_file_names.txt";
	
	static int getNameScore(String name, int position) {
		int sum = 0;
		for (int i = 0; i < name.length(); i++) {
			sum += name.charAt(i) - 64;
		}
		return sum*position;
	}
	
	static int getNameScores() {
		int score = 0;
		String data = "";
		
		try {
		    data = new String(Files.readAllBytes(Paths.get(fileName)));
		    data = data.replace("\"", "");
		    String[] names = data.split(",");
		    
		    Arrays.sort(names);
		    
		    for (int i = 0; i < names.length; i++) {
		    	score += getNameScore(names[i], i+1);
		    }
		    
		} catch (IOException e) {
			//if an I/O error occurs reading from the stream
			
		} catch (OutOfMemoryError e) {
			// if an array of the required size cannot be allocated,
			// for example the file is larger that 2GB		
		} catch (SecurityException e) {
    		// In the case of the default provider, and a security manager is installed, 
			// the checkRead method is invoked to check read access to the file.	
		}
        
		return score;
	}
	
	
	public static void main(String[] args) throws IOException {

		System.out.println(getNameScores());
	}

}
