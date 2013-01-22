package ebms.server.core.impl.unittest;

import ebms.server.core.pkj.EBMS_consts;
import ebms.server.core.impl.Connector;
import ebms.server.core.interfaces.EBMSConnectorInterface;
import java.sql.ResultSet;
import java.sql.SQLException;

public class ConnectorTestClass {

	/**
	 * @param args
	 * @throws SQLException 
	 */
	public static void main(String[] args) throws SQLException {
		
		EBMS_consts.initConsts("../DbConfig.cfg");
		
		EBMSConnectorInterface conn = new Connector();
		boolean bOpened = conn.openDb();
		System.out.println( "Connecting :" + bOpened );
		if(bOpened)
		{
			ResultSet result = conn.execute("select * from "+EBMS_consts.TblUserLogin.tablename);
			
			// displaying
			while(result.next())
			{
				System.out.println(result.getString(EBMS_consts.TblUserLogin.fieldUserId) +" " + result.getString(EBMS_consts.TblUserLogin.fieldUsername) + " " + result.getString(EBMS_consts.TblUserLogin.fieldPassword));
			}		
		}
		
		boolean bClosed = conn.closeDb();
		

	}

}
