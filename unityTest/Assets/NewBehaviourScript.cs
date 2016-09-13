using UnityEngine;
using System.Collections;
using System.Runtime.InteropServices;

public class NewBehaviourScript : MonoBehaviour {

    [DllImport("cppDll")]
    private static extern int add(int x, int y);

    // Use this for initialization
    void Start () {
        int x = 0;
        x = add(10, 20);
        Debug.Log(x);
	}
	
	// Update is called once per frame
	void Update () {
	
	}
}
