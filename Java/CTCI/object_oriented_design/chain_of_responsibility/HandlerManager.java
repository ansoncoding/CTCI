package chain_of_responsibility;

public class HandlerManager implements ComplaintHandler {
	
	private ComplaintHandler nextHandler;
	
	@Override
	public void setNextHandler(ComplaintHandler h) {
		nextHandler = h; 
	}

	@Override
	public void handleComplaint(Complaint complaint) {
		if (complaint.getLevel() == Complaint.ComplaintLevel.MANAGER) {
			System.out.println(complaint.getComplaint() + " has been handled by manager");
		}  else {
			nextHandler.handleComplaint(complaint);
		}
	}
}
