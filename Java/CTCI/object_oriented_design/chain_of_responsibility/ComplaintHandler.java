package chain_of_responsibility;

public interface ComplaintHandler {
	public void setNextHandler(ComplaintHandler h);
	public void handleComplaint(Complaint complaint);
}
