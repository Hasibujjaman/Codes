package com.example.fragmentexample3;

import android.content.Intent;
import android.os.Bundle;

import androidx.annotation.NonNull;
import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentResultListener;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import java.util.Objects;

/**
 * A simple {@link Fragment} subclass.
 * Use the {@link FragmentB#newInstance} factory method to
 * create an instance of this fragment.
 */
public class FragmentB extends Fragment {
    TextView txtFragB;
    EditText edtFragB;
    Button btnFragB_SendToMain;

    // TODO: Rename parameter arguments, choose names that match
    // the fragment initialization parameters, e.g. ARG_ITEM_NUMBER
    private static final String ARG_PARAM1 = "param1";


   /* // TODO: Rename and change types of parameters
    private String mParam1;
    private String mParam2;*/

    public FragmentB() {
        // Required empty public constructor
    }

    /**
     * Use this factory method to create a new instance of
     * this fragment using the provided parameters.
     *
     * @param param1 Parameter 1.
     * @return A new instance of fragment FragmentB.
     */
    // TODO: Rename and change types and number of parameters
    public static FragmentB newInstance(String param1) {
        FragmentB fragment = new FragmentB();
        Bundle args = new Bundle();
        args.putString(ARG_PARAM1, param1);
        fragment.setArguments(args);
        return fragment;
    }


    /*@Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        if (getArguments() != null) {
            mParam1 = getArguments().getString(ARG_PARAM1);
            mParam2 = getArguments().getString(ARG_PARAM2);
        }
    }*/

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        View view1 = inflater.inflate(R.layout.fragment_b, container, false);
        //using data received from Fragment A
        getParentFragmentManager().setFragmentResultListener("dataFromA", this, new FragmentResultListener() {
            @Override
            public void onFragmentResult(@NonNull String requestKey, @NonNull Bundle result) {
                String data = result.getString("dfA");
                txtFragB = view1.findViewById(R.id.txtFragB);
                txtFragB.setText(data);

            }
        });
        //sending data from fragment B to main activity
        btnFragB_SendToMain = view1.findViewById(R.id.btnFragB_SendToMain);
        btnFragB_SendToMain.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                edtFragB = view1.findViewById(R.id.edtFragB);
                //method 1 (intent passing)
//                if(!edtFragB.getText().toString().equals("")) {
//                    Intent intent = new Intent(getActivity(), MainActivity.class);
//
//                    intent.putExtra("dfB", edtFragB.getText().toString());
//
//                    startActivity(intent);
//                }
                //method 2 (MainActivity class method)
                if(!edtFragB.getText().toString().equals("")){
                    if(getActivity() != null)
                        ((MainActivity)getActivity()).setTxtMain(edtFragB.getText().toString()); // getActivity() will return reference of MainActivity because FragmentB is on MainActivity
                }

            }
        });


        // Inflate the layout for this fragment
        return view1;
    }
}