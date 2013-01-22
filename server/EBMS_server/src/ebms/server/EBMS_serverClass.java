package ebms.server;

import java.io.InputStream;

import ebms.server.core.pkj.Server;
import ebms.server.core.interfaces.ServerInterface;

public class EBMS_serverClass {
	
	public EBMS_serverClass(){
		mServer = createServer();
	}
	
	public boolean login(String user,String password){
		return mServer.login(user, password);
	}
	
	public boolean hasPrivilege(String user,String password,String level,String oper){
		return mServer.hasPrivilege(user,password,level,oper);
	}
	
	public String doOperation(String user,String password,String level,String oper){
		return mServer.doOperation(user, password, level, oper);
	}
	
	private ServerInterface createServer(){	
		InputStream stream = this.getClass().getResourceAsStream("DbConfig.cfg");	
		return new Server(stream);
	} 
	
	private ServerInterface mServer=null;

}
