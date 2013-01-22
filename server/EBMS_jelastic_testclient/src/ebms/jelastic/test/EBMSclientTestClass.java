package ebms.jelastic.test;

import java.rmi.RemoteException;


import ebms.server.EBMS_serverClassPortTypeProxy;


public class EBMSclientTestClass {

	public static void main(String[] args) {
		
		try
		{			
			EBMS_serverClassPortTypeProxy serverProxy = new EBMS_serverClassPortTypeProxy();
			boolean bLogin = serverProxy.login("100200300","jyo123#");
			System.out.println("Login :" + bLogin);
			
			
		}catch(RemoteException ex)
		{
			System.out.println("RemoteException :" +ex.getMessage());
		}
	}

}
