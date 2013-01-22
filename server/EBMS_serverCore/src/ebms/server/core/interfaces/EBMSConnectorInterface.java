package ebms.server.core.interfaces;

public interface EBMSConnectorInterface {
	void setTraceLevel(int trace);
	boolean openDb();
	boolean closeDb();
	boolean isOpen();
	java.sql.ResultSet execute(String query);	
}
