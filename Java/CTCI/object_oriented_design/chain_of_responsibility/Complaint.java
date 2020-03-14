package chain_of_responsibility;

public class Complaint {
	
	String complaint;
	ComplaintLevel level;
	Complaint(String c, ComplaintLevel l) {
		complaint = c;
		level = l;
	}
	public enum ComplaintLevel {
		TRIVIAL,
		CLERK,
		MANAGER,
		HEAD_OFFICE
	}
	public String getComplaint() {
		return complaint;
	}
	public ComplaintLevel getLevel() {
		return level;
	}
}
