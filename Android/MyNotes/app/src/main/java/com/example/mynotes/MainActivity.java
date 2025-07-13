package com.example.mynotes;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.lifecycle.Observer;
import androidx.lifecycle.ViewModelProvider;
import androidx.recyclerview.widget.ItemTouchHelper;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

import com.example.mynotes.databinding.ActivityMainBinding;

import java.util.List;

public class MainActivity extends AppCompatActivity {
    ActivityMainBinding binding;
    private NoteViewModel noteViewModel;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        noteViewModel = new ViewModelProvider(this,ViewModelProvider.AndroidViewModelFactory.getInstance(this.getApplication())).get(NoteViewModel.class);
        binding.btnFlt.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent(MainActivity.this, DataInsert.class);
                intent.putExtra("mode","AM");
                startActivityForResult(intent,1);
            }
        });

        binding.recyclerView.setLayoutManager(new LinearLayoutManager(this));
        binding.recyclerView.setHasFixedSize(true );
        RecyclerViewAdapter adapter = new RecyclerViewAdapter();
        binding.recyclerView.setAdapter(adapter);

        noteViewModel.getData().observe(this, new Observer<List<NoteModel>>() {
            @Override
            public void onChanged(List<NoteModel> noteModels) {
                adapter.submitList(noteModels);
            }
        });

        new ItemTouchHelper(new ItemTouchHelper.SimpleCallback(0,ItemTouchHelper.RIGHT | ItemTouchHelper.LEFT) {
            @Override
            public boolean onMove(@NonNull RecyclerView recyclerView, @NonNull RecyclerView.ViewHolder viewHolder, @NonNull RecyclerView.ViewHolder target) {
                return false;
            }
            @Override
            public void onSwiped(@NonNull RecyclerView.ViewHolder viewHolder, int direction) {
                if(direction == ItemTouchHelper.RIGHT) {
                    noteViewModel.delete(adapter.getNote(viewHolder.getAdapterPosition()));
                }
                else{
                    Toast.makeText(MainActivity.this,"Updating",Toast.LENGTH_SHORT).show();
                    Intent intent = new Intent(MainActivity.this, DataInsert.class);
                    intent.putExtra("mode","UM");
                    intent.putExtra("keyTitle",adapter.getNote(viewHolder.getAdapterPosition()).getTitle());
                    intent.putExtra("keyNote",adapter.getNote(viewHolder.getAdapterPosition()).getNote());
                    intent.putExtra("ID",adapter.getNote(viewHolder.getAdapterPosition()).getId());
                    startActivityForResult(intent,2);
                }
            }
        }).attachToRecyclerView(binding.recyclerView);
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if(requestCode == 1){
            String title = data.getStringExtra("keyTitle");
            String note = data.getStringExtra("keyNote");
            NoteModel noteModel = new NoteModel(title, note);
            noteViewModel.insert(noteModel);
            Toast.makeText(this,"Note added",Toast.LENGTH_SHORT).show();
        }
        if(requestCode == 2){
            String title = data.getStringExtra("keyTitle");
            String note = data.getStringExtra("keyNote");
            NoteModel noteModel = new NoteModel(title, note);
            noteModel.setId(data.getIntExtra("ID",0));
            noteViewModel.update(noteModel);
            Toast.makeText(this,"Note updated",Toast.LENGTH_SHORT).show();
        }

    }
}