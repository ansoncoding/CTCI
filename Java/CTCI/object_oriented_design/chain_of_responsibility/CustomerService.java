package chain_of_responsibility;

public class CustomerService {

	public static void main(String[] args) {
		ComplaintHandler clerk = new HandlerClerk();
		ComplaintHandler manager = new HandlerManager();
		ComplaintHandler headoffice = new HandlerHeadOffice();
		clerk.setNextHandler(manager);
		manager.setNextHandler(headoffice);
		
		Complaint c = new Complaint("I want a refund", Complaint.ComplaintLevel.CLERK);
		clerk.handleComplaint(c);
		
		Complaint c2 = new Complaint("I want a refund but don't have my receipt", Complaint.ComplaintLevel.MANAGER);
		clerk.handleComplaint(c2);
		
		Complaint c3 = new Complaint("Someone screwed up my sale so badly I want to sue the company", Complaint.ComplaintLevel.HEAD_OFFICE);
		clerk.handleComplaint(c3);
		
		Complaint c4 = new Complaint("Homeless guy is here again", Complaint.ComplaintLevel.TRIVIAL);
		clerk.handleComplaint(c4);
	}

}
