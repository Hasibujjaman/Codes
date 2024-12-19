package com.example.mynotes;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;

import com.example.mynotes.databinding.ActivityDataInsertBinding;

public class DataInsert extends AppCompatActivity {
    ActivityDataInsertBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        binding = ActivityDataInsertBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        String mode = getIntent().getStringExtra("mode");
        if (mode.equals("UM")) {
            setTitle("Update Mode");
            binding.edtTitle.setText(getIntent().getStringExtra("keyTitle"));
            binding.edtNote.setText(getIntent().getStringExtra("keyNote"));
            int id = getIntent().getIntExtra("ID", 0);
            binding.btnAdd.setText("Update Note");

            binding.btnAdd.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                    Intent intent = new Intent();
                    intent.putExtra("keyTitle", binding.edtTitle.getText().toString());
                    intent.putExtra("keyNote", binding.edtNote.getText().toString());
                    intent.putExtra("ID", id);
                    setResult(RESULT_OK, intent);
                    finish();

                }
            });

        }
        else {
            setTitle("Add Mode");
            binding.btnAdd.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                    Intent intent = new Intent();
                    intent.putExtra("keyTitle", binding.edtTitle.getText().toString());
                    intent.putExtra("keyNote", binding.edtNote.getText().toString());
                    setResult(RESULT_OK, intent);
                    finish();
                }
            });
        }
    }

    @Override
    public void onBackPressed() {
        super.onBackPressed();
        startActivity(new Intent(DataInsert.this,MainActivity.class));
    }
}