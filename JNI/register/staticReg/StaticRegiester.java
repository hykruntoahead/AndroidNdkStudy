
class StaticRegiester {
    static{
       System.load("/home/hyk/AndroidStudioProjects/AndroidNdkStudy/JNI/register/staticReg/build/libfirstLib.so");
    }

    public native void printNativeMsg();
    public native String obtainNativeReturnMsg();

    public static void main(String[] args) {
        StaticRegiester staticRegiester = new StaticRegiester();
        staticRegiester.printNativeMsg(); 
        try{
        Thread.sleep(100);
        }catch(Exception e){
            e.printStackTrace();
        }

        System.out.println(staticRegiester.obtainNativeReturnMsg());
    }
}