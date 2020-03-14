package chain_of_responsibility;

public class HandlerClerk implements ComplaintHandler {
	
private ComplaintHandler nextHandler;
	
	@Override
	public void setNextHandler(ComplaintHandler h) {
		nextHandler = h; 
	}

	@Override
	public void handleComplaint(Complaint complaint) {
		if (complaint.getLevel() == Complaint.ComplaintLevel.CLERK) {
			System.out.println(complaint.getComplaint() + " has been handled by clerk");
		}  else {
			nextHandler.handleComplaint(complaint);
		}
	}
}
