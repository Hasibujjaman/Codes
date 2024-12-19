package com.example.fragmentexample3;

import android.os.Bundle;

import androidx.fragment.app.Fragment;

import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;


public class FragmentA extends Fragment {
    TextView txtFragA;
    EditText edtFragA;
    Button btnFragA_SendToFragB;

    private static final String key1 = "key1";
    //private static final String key2 = "key2";



    public FragmentA() {
        // Required empty public constructor
    }

    //Function for getting FragmentA instance with arguments loaded from other classes
    //for sending data from main activity to fragment A (method 2)
    public static FragmentA getInstance(String value1){
        FragmentA fragmentA = new FragmentA();
        Bundle bundle = new Bundle();
        bundle.putString(key1,value1);
        fragmentA.setArguments(bundle);
        return fragmentA;
    }






    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {

        View view1 = inflater.inflate(R.layout.fragment_a, container, false);
        txtFragA = view1.findViewById(R.id.txtFragA);
        //using data fetched from main activity
        if(getArguments() != null){
            String data1 = getArguments().getString("key1");
            String Data1 = getArguments().getString(key1);

            txtFragA.setText(data1);
            Log.d("Data from main act ","Data is : "+Data1);

        }
        //Passing Data from Fragment A to Fragment B
        btnFragA_SendToFragB = view1.findViewById(R.id.btnFragA_SendToFragB);

        btnFragA_SendToFragB.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                edtFragA = view1.findViewById(R.id.edtFragA);
                if(!edtFragA.getText().toString().equals("")) {
                    Bundle bundle = new Bundle();
                    bundle.putString("dfA", edtFragA.getText().toString());
                    getParentFragmentManager().setFragmentResult("dataFromA",bundle);
                    edtFragA.setText("");
                    Toast.makeText(getContext(),"Data has been sent from Fragment A to Fragment B",Toast.LENGTH_SHORT).show();
                }


            }
        });

        // Inflate the layout for this fragment
        return view1;
    }
}