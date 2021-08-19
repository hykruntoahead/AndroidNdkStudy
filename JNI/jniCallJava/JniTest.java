public class JniTest{
    static{
        System.load("/home/hyk/AndroidStudioProjects/AndroidNdkStudy/JNI/jniCallJava/build/libdrLib.so");
    }

    private int age ;
    private String name ;
    private static boolean man = false;

    protected native void JniCallJavaMember();
    protected native void JniCallJavaStaticMember();
    protected native void JniCallJavaMethod();
    protected native void JniCallJavaStaticMethod();

   JniTest(){

   }

    public JniTest(int age, String name) {
        this.age = age;
        this.name = name;
    }

    protected int tenYearLaterAge(){
        System.out.println("input age is = "+this.age);
        return age + 10;
    }

    protected static void changeSexToOther(){ 
        man=!man;
    }

    public static void main(String[] args) {
        JniTest jniTest = new JniTest();
        jniTest.age = 28;
        jniTest.name = "boolahyg";
        man = true;
        jniTest.JniCallJavaMember();
        jniTest.JniCallJavaStaticMember();
        System.out.println("==================================================");
        jniTest.JniCallJavaMethod();
        jniTest.JniCallJavaStaticMethod();
    }
}