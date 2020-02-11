package strings_and_arrays;

public class StringEmptyException extends Exception{
	private String msg = "String is unexpectedly empty";
	public String getMessage() {
		return msg;
	}
}
