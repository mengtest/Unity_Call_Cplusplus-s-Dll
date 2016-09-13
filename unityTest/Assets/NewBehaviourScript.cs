using UnityEngine;
using System.Collections;
using System.Runtime.InteropServices;

public class NewBehaviourScript : MonoBehaviour {

    [DllImport("cppDll")]
    private static extern int add(int x, int y);


    [StructLayout(LayoutKind.Sequential)]
    public struct CppStruct
    {
        public int a;
        public int b;
        public int c;
    }

    [DllImport("cppDll")]
    private static extern bool getStructData(ref CppStruct info);


    // Use this for initialization
    void Start () {
        int x = 0;
        x = add(10, 20);
        Debug.Log(x);

        CppStruct info = new CppStruct();
        getStructData(ref info);
        Debug.Log(info.a);
    }
	
	// Update is called once per frame
	void Update () {
	
	}
}
