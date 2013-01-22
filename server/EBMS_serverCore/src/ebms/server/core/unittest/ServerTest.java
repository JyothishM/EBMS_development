package ebms.server.core.unittest;

import java.sql.SQLException;
import ebms.server.core.interfaces.ServerInterface;
import ebms.server.core.pkj.Server;



public class ServerTest {

	/**
	 * @param args
	 * @throws 5 
	 */
	public static void main(String[] args) throws SQLException {		
		ServerInterface server = new Server("../DbConfig.cfg");
		boolean bLogin = server.login("100200301", "jo123#");
		System.out.println("Login :"+bLogin);
		
		boolean bHasPrivilage = server.hasPrivilege("100200301", "jo123#","100201","adduser");
		System.out.println("bHasPrivilage :"+bHasPrivilage);
	}
}
