package com.example.fragmentexample2;

import androidx.appcompat.app.AppCompatActivity;
import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentManager;
import androidx.fragment.app.FragmentTransaction;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    Button btnFrag1, btnFrag2, btnFrag3;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        btnFrag1 = findViewById(R.id.btnFrag1);
        btnFrag2 = findViewById(R.id.btnFrag2);
        btnFrag3 = findViewById(R.id.btnFrag3);

        loadFragment(new FragmentA(),false); //setting default fragment

        btnFrag1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                loadFragment(new FragmentA(),true);
                Toast.makeText(MainActivity.this,"Fragment A loaded",Toast.LENGTH_SHORT).show();
            }
        });

        btnFrag2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                loadFragment(new FragmentB(),true);
                Toast.makeText(MainActivity.this,"Fragment B loaded",Toast.LENGTH_SHORT).show();
            }
        });

        btnFrag3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                loadFragment(new FragmentC(),true);
                Toast.makeText(MainActivity.this,"Fragment C loaded",Toast.LENGTH_SHORT).show();
            }
        });

    }
    public void loadFragment(Fragment fragment, boolean is_loaded){
        FragmentManager fm = getSupportFragmentManager();
        FragmentTransaction ft = fm.beginTransaction();
        if(is_loaded)
            ft.replace(R.id.frameCont,fragment);
        else
            ft.add(R.id.frameCont,fragment);

        ft.commit();
    }
}