package ebms.server.test;

import ebms.server.EBMS_serverClass;

public class EBMS_serverTestClass {

	public static void main(String[] args) {

		EBMS_serverClass server = new EBMS_serverClass();
		boolean bLogin = server.login("jyothish", "jyo123#");
		System.out.println("login :"+bLogin);
		
	}

}
