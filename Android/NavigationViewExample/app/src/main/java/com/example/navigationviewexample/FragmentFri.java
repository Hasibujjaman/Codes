package com.example.navigationviewexample;

import android.graphics.Typeface;
import android.os.Bundle;

import androidx.fragment.app.Fragment;

import android.view.Gravity;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

/**
 * A simple {@link Fragment} subclass.
 * Use the {@link FragmentFri newInstance} factory method to
 * create an instance of this fragment.
 */
public class FragmentFri extends Fragment {

    /*// TODO: Rename parameter arguments, choose names that match
    // the fragment initialization parameters, e.g. ARG_ITEM_NUMBER
    private static final String ARG_PARAM1 = "param1";
    private static final String ARG_PARAM2 = "param2";

    // TODO: Rename and change types of parameters
    private String mParam1;
    private String mParam2;*/

    public FragmentFri() {
        // Required empty public constructor
    }

    /*// TODO: Rename and change types and number of parameters
    public static FragmentFri newInstance(String param1, String param2) {
        FragmentFri fragment = new FragmentFri();
        Bundle args = new Bundle();
        args.putString(ARG_PARAM1, param1);
        args.putString(ARG_PARAM2, param2);
        fragment.setArguments(args);
        return fragment;
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        if (getArguments() != null) {
            mParam1 = getArguments().getString(ARG_PARAM1);
            mParam2 = getArguments().getString(ARG_PARAM2);
        }
    }*/

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        View view = inflater.inflate(R.layout.fragment_fri, container, false);
        TextView txtFragFri = view.findViewById(R.id.txtFragFri);
        txtFragFri.setText("Fragment Friday");
        txtFragFri.setTypeface(null, Typeface.BOLD);
        txtFragFri.setTextSize(21);
        txtFragFri.setTextColor(getResources().getColor(R.color.my_color));
        txtFragFri.setGravity(Gravity.CENTER);

        return view;
    }
}