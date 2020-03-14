package chain_of_responsibility;

public class HandlerHeadOffice implements ComplaintHandler {
	@Override
	public void setNextHandler(ComplaintHandler h) {
		 
	}

	@Override
	public void handleComplaint(Complaint complaint) {
		if (complaint.getLevel() == Complaint.ComplaintLevel.HEAD_OFFICE) {
			System.out.println(complaint.getComplaint() + " has been handled by head office");
		}  else {
			System.out.println(complaint.getComplaint() + " is trivial, disregard");
		}
	}

}
