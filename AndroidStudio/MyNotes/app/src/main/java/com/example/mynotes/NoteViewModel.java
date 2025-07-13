package com.example.mynotes;

import android.app.Application;

import androidx.annotation.NonNull;
import androidx.lifecycle.AndroidViewModel;
import androidx.lifecycle.LiveData;

import java.util.List;

public class NoteViewModel extends AndroidViewModel {
    private NoteRepo noteRepo;
    private LiveData<List<NoteModel>> noteList;
    public NoteViewModel(@NonNull Application application) {
        super(application);

        noteRepo = new NoteRepo(application);
        noteList = noteRepo.getAllData();
    }
    public void insert(NoteModel noteModel){
        noteRepo.insertData(noteModel);
    }
    public void update(NoteModel noteModel){
        noteRepo.updateData(noteModel);
    }
    public void delete(NoteModel noteModel){
        noteRepo.deleteData(noteModel);
    }
    public LiveData<List<NoteModel>> getData(){
        return noteRepo.getAllData();
    }


}
