package ebms.server.core.interfaces;

public interface ServerInterface {
	void setTraceLevel(int trace);
	boolean login(String user,String password);
	boolean hasPrivilege(String user,String password,String level,String oper);
	String doOperation(String user,String password,String level,String oper);
}
