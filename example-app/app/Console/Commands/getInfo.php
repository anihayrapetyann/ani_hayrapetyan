<?php

namespace App\Console\Commands;

use App\Models\User;
use Illuminate\Console\Command;
use Illuminate\Support\Facades\Cache;

class getInfo extends Command
{
    /**
     * The name and signature of the console command.
     *
     * @var string
     */
    protected $signature = 'get:user {userid}';

    /**
     * The console command description.
     *
     * @var string
     */
    protected $description = 'Gef info about user from db';

    /**
     * Execute the console command.
     */
    public function handle()
    {
//        Cache::put('key', 'hello', 60);
//        $cacheValue = Cache::get('key');
//        dd($cacheValue);
//        $id = $this->argument('userid');
//        $user = User::query()->where('id', $id)->first();
//        if(!$user){
//            return $this->error('There is no user with '.$id.' id');
//        }
//        dd($user->toArray());
//        return $user;
//        $users = User::all();
//        $map = [];
//        foreach ($users as $user) {
//            $map[] = $user->user_name;
//        }
//        dd($users);
        $collection = collect([1, 2, 3]);

//        dd($collection->push(6)->avg());
        dd($collection->random());
    }
}
